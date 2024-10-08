#include "SceneManager.h"
#include "definitions.h"
#include <stb/stb_image.h>
#include <glm/gtc/random.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

void SceneManager::readFile(const std::string file)
{
	std::ifstream inputFile(file);
	if (!inputFile) {
		std::cerr << "Error: Could not open the scene config file!" << std::endl;
		_camera = std::unique_ptr<Camera>(new Camera(glm::vec3(0.0f, 1.5f, 4.0f)));
	}
	else
	{
		std::vector<float> projection;
		std::vector<float> cameraValues;
		std::vector<float> cameraPos;
		std::vector<float> clearColor;
		std::vector<float> cubeColor;
		float rotateStep{ _rotateStep };
		std::vector<float> autoRotateAxis;
		float autoRotateSpeed{ 1.0 };
		std::string line;
		while (std::getline(inputFile, line)) {
			std::istringstream iss(line);
			std::string identifier;
			iss >> identifier;

			// Check the identifier and read corresponding values into the vector
			if (identifier == "PROJECTION") {
				float value;
				while (iss >> value) {
					projection.push_back(value);
				}
			}
			else if (identifier == "CAMERA_VALUES") {
				float value;
				while (iss >> value) {
					cameraValues.push_back(value);
				}
			}
			else if (identifier == "CAMERA_POS") {
				float value;
				while (iss >> value) {
					cameraPos.push_back(value);
				}
			}
			else if (identifier == "CLEAR_COLOR") {
				float value;
				while (iss >> value) {
					clearColor.push_back(value);
				}
			}
			else if (identifier == "CUBE_COLOR") {
				float value;
				while (iss >> value) {
					cubeColor.push_back(value);
				}
			}
			else if (identifier == "ROTATE_STEP") {
				iss >> rotateStep;
			}
			else if (identifier == "AUTOROTATE_AXIS") {
				float value;
				while (iss >> value) {
					autoRotateAxis.push_back(value);
				}
			}
			else if (identifier == "AUTOROTATE_SPEED") {
				iss >> autoRotateSpeed;
			}
		}

		// init camera
		_camera = std::unique_ptr<Camera>(new Camera(glm::vec3(cameraPos[0], cameraPos[1], cameraPos[2])));
		_camera->init(projection, cameraValues);

		_clearColor = glm::vec3(clearColor[0], clearColor[1], clearColor[2]);
		for (const auto& obj : _objs)
		{
			obj->setCubeColor(glm::vec3(cubeColor[0], cubeColor[1], cubeColor[2]));
			obj->setAutoRotateAxis(glm::vec3(autoRotateAxis[0], autoRotateAxis[1], autoRotateAxis[2]));
			obj->setAutoRotateSpeed(autoRotateSpeed);
		}
		_rotateStep = rotateStep;
	}
}

Object* SceneManager::getObjectByID(GLuint objectID)
{
	for (auto it = _objs.begin(); it != _objs.end(); ++it)
	{
		if ((*it)->getID() == objectID)
			return it->get();
	}
	return 0;
}

void SceneManager::init()
{
	readFile(SCENE_CONFIG_PATH);

	// configure global opengl state
	glEnable(GL_DEPTH_TEST);

	_objs.clear();
	_objs.push_back(std::unique_ptr<Object>(new Object()));

	setupVertexData();

	loadTextures();

	setupShaders();
}

void SceneManager::setupVertexData()
{
	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);
	glBindVertexArray(_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	for (auto it = _objs.begin(); it != _objs.end(); ++it)
	{
		(*it)->setupVertexData();
	}
}

void SceneManager::loadTextures()
{
	// load and create texture 
	glGenTextures(1, &_texture0);
	glBindTexture(GL_TEXTURE_2D, _texture0);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
	unsigned char* data = stbi_load(IMAGE_PATH, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

void SceneManager::setupShaders()
{
	for (auto it = _objs.begin(); it != _objs.end(); ++it)
	{
		(*it)->setupShader();
	}
}

void SceneManager::render(float deltaTime)
{
	_deltaTime = deltaTime;
	glClearColor(_clearColor.r, _clearColor.g, _clearColor.b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// bind textures on corresponding texture units
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _texture0);

	for (const auto& obj : _objs)
	{
		const auto& shader = obj->getShader();
		obj->checkAutoRotate();
		shader->setMat4("projection", _camera->getProjectionMat());
		shader->setMat4("model", obj->getModelMat());
		shader->setMat4("view", _camera->getViewMat());
		shader->use();
	}

	glBindVertexArray(_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void SceneManager::onInput(GLFWwindow* window)
{
	// camera movement
	const std::vector<int> cameraKeys = { GLFW_KEY_KP_8, GLFW_KEY_KP_2, GLFW_KEY_KP_4, GLFW_KEY_KP_6, GLFW_KEY_PAGE_UP, GLFW_KEY_PAGE_DOWN, GLFW_KEY_HOME, GLFW_KEY_END };
	const std::vector<CAMERA_MOVEMENT> cameraDirections = { FORWARD, BACKWARD, LEFT, RIGHT, UP, DOWN, ROTATE_UP, ROTATE_DOWN };
	for (auto i = 0; i < cameraKeys.size(); ++i)
	{
		if (glfwGetKey(window, cameraKeys[i]) == GLFW_PRESS)
		{
			_camera->processDirectiveMovement(cameraDirections[i], _deltaTime);
		}
	}

	// object rotation
	const std::vector<int> objectKeys = { GLFW_KEY_UP, GLFW_KEY_DOWN, GLFW_KEY_LEFT, GLFW_KEY_RIGHT};
	const std::vector<float> objectRotateAngle = { _rotateStep, -_rotateStep, _rotateStep, -_rotateStep };
	const std::vector<glm::vec3> objectRotateAxis = { glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f) };
	for (auto i = 0; i < objectKeys.size(); ++i)
	{
		if (glfwGetKey(window, objectKeys[i]) == GLFW_PRESS)
		{
			for (const auto& obj : _objs)
			{
				obj->rotate(objectRotateAngle[i], objectRotateAxis[i]);
			}
		}
	}

	// change cube faces
	const auto faceKeys = { GLFW_KEY_1, GLFW_KEY_2, GLFW_KEY_3, GLFW_KEY_4, GLFW_KEY_5, GLFW_KEY_6 };
	int32_t faceConfig = 0;
	bool hasChangeCubeFace = false;
	for (auto it = faceKeys.begin(); it != faceKeys.end(); ++it)
	{
		if (glfwGetKey(window, *it) == GLFW_PRESS)
		{
			// set a random color for the face correspond to the key pressed
			faceConfig += (1 << std::distance(faceKeys.begin(), it));
			hasChangeCubeFace = true;
		}
	}
	if (hasChangeCubeFace)
	{
		const auto color = glm::ballRand<float>(0.5f) + glm::vec3(0.5f, 0.5f, 0.5f);
		for (const auto& obj : _objs)
		{
			obj->updateFaceColor(color, faceConfig);
		}
	}

	// use textures
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
	{
		for (const auto& obj : _objs)
		{
			obj->toggleUseTexture();
		}
	}

	// auto rotate
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		for (const auto& obj : _objs)
		{
			obj->toggleAutoRotate();
		}
	}
}

void SceneManager::onMouseMovement(float xOffset, float yOffset)
{
	_camera->processMouseMovement(xOffset, yOffset);
}

void SceneManager::onMouseScroll(double yOffset)
{
	for (const auto& obj : _objs)
	{
		obj->onMouseScroll(yOffset * _scrollSensitivity);
	}
}

void SceneManager::updateScene(float deltaTime)
{
}

void SceneManager::readKey(unsigned char key)
{
}

void SceneManager::cleanUp()
{
	glDeleteVertexArrays(1, &_VAO);
	glDeleteBuffers(1, &_VBO);

	for (const auto& obj : _objs)
	{
		obj->cleanUp();
	}
}
