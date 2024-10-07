#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "core/Shader.h"
#include "definitions.h"
#include <stb/stb_image.h>
#include "definitions.h"
#include "SceneManager.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/random.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void setupVertexData();
void loadTexture();
void render(GLFWwindow* window);
void cleanUp();
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

uint32_t _VAO, _VBO/*, _EBO*/;
uint32_t _texture0;
Shader _shader;
// camera
Camera camera(glm::vec3(-0.5f, 1.5f, 4.0f));
float lastX = WINDOW_WIDTH / 2.0f;
float lastY = WINDOW_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

// cube model mat
glm::mat4 modelMat = glm::mat4(1.0f);
glm::mat4 projectionMat = glm::mat4(1.0f);

glm::vec3 cubeColor = glm::vec3(0.0f, 0.0f, 1.0f);
bool useTexture = false;

int main()
{
	// init glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// create window
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGLCubeDemo", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	// setup viewport
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	//glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// init GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);

	// compile shaders
	_shader = Shader(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);

	// setup vertex data
	setupVertexData();

	loadTexture();

	// render loop
	while (!glfwWindowShouldClose(window))
	{
		render(window);
	}

	// clean/delete resources
	cleanUp();
	glfwTerminate();
	return 0;
}

void setupVertexData()
{
	//float vertices[] = {
	//	// positions          /*// colors         */  // texture coords
	//	 0.5f,  0.5f, 0.0f,   /*-1.0f, 0.0f, 0.0f,*/   1.0f, 1.0f, // top right
	//	 0.5f, -0.5f, 0.0f,   /*-1.0f, 0.0f, 0.0f,*/   1.0f, 0.0f, // bottom right
	//	-0.5f, -0.5f, 0.0f,   /*-1.0f, 0.0f, 0.0f,*/   0.0f, 0.0f, // bottom left
	//	-0.5f,  0.5f, 0.0f,   /*-1.0f, 0.0f, 0.0f,*/   0.0f, 1.0f  // top left 
	//};
	//uint32_t indices[] = {
	//	0, 1, 3,  // first Triangle
	//	1, 2, 3   // second Triangle
	//};
	float vertices[] = {
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,	0.0,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,	0.0,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,	0.0,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,	0.0,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,	0.0,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,	0.0,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,	1.0,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,	1.0,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,	1.0,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,	1.0,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,	1.0,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,	1.0,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,	2.0,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,	2.0,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,	2.0,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,	2.0,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,	2.0,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,	2.0,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,	3.0,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,	3.0,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,	3.0,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,	3.0,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,	3.0,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,	3.0,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,	4.0,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,	4.0,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,	4.0,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,	4.0,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,	4.0,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,	4.0,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,	5.0,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,	5.0,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,	5.0,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,	5.0,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,	5.0,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,	5.0
	};

	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);
	//glGenBuffers(1, &_EBO);
	glBindVertexArray(_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// face id attribute
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);

	//// unbind vbo
	//glBindBuffer(GL_ARRAY_BUFFER, 0);

	//// keep ebo bounded here, as it is stored in the vao

	//// unbind vao
	//glBindVertexArray(0);
}

void loadTexture()
{
	// load and create a texture 
// -------------------------
	// texture 1
	// ---------
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

	// tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
	// -------------------------------------------------------------------------------------------
	_shader.use();
	_shader.setInt("texture0", 0);
	_shader.setInt("uFaceConfig", (1 << 6) - 1);	// set all faces
	_shader.setVec3("uColor", cubeColor);
	_shader.setVec3("cubeColor", cubeColor);
	_shader.setBool("useTexture", useTexture);
}

void render(GLFWwindow* window)
{
	// per-frame time logic
	// --------------------
	float currentFrame = static_cast<float>(glfwGetTime());
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	processInput(window);

	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// bind textures on corresponding texture units
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _texture0);
	
	// get matrix's uniform location and set matrix
	_shader.use();

	// create transformations
	projectionMat = glm::perspective(glm::radians(camera.Zoom), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
	glm::mat4 view = camera.GetViewMatrix();
	// pass transformation matrices to the shader
	_shader.setMat4("projection", projectionMat); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
	_shader.setMat4("view", view);
	_shader.setMat4("model", modelMat);

	glBindVertexArray(_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	// swap buffers
	glfwSwapBuffers(window);
	// poll IO events
	glfwPollEvents();
}

void cleanUp()
{
	glDeleteVertexArrays(1, &_VAO);
	glDeleteBuffers(1, &_VBO);
	//glDeleteBuffers(1, &_EBO);
	_shader.cleanUp();
}

void processInput(GLFWwindow* window)
{
	// close when press ESC
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	// camera handling
	if (glfwGetKey(window, GLFW_KEY_KP_8) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_KP_2) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_KP_4) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_KP_6) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_PAGE_UP) == GLFW_PRESS)
		camera.ProcessKeyboard(UP, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS)
		camera.ProcessKeyboard(DOWN, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_HOME) == GLFW_PRESS)
		camera.ProcessKeyboard(ROTATE_UP, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_END) == GLFW_PRESS)
		camera.ProcessKeyboard(ROTATE_DOWN, deltaTime);

	// rotate the cube
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		modelMat = glm::rotate(modelMat, glm::radians(0.5f), glm::vec3(1.0f, 0.0f, 0.0f));
		_shader.setMat4("model", modelMat);
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		modelMat = glm::rotate(modelMat, glm::radians(-0.5f), glm::vec3(1.0f, 0.0f, 0.0f));
		_shader.setMat4("model", modelMat);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		modelMat = glm::rotate(modelMat, glm::radians(0.5f), glm::vec3(0.0f, 1.0f, 0.0f));
		_shader.setMat4("model", modelMat);
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		modelMat = glm::rotate(modelMat, glm::radians(-0.5f), glm::vec3(0.0f, 1.0f, 0.0f));
		_shader.setMat4("model", modelMat);
	}

	// change cube faces
	const auto faceKeys = { GLFW_KEY_1, GLFW_KEY_2, GLFW_KEY_3, GLFW_KEY_4, GLFW_KEY_5, GLFW_KEY_6 };
	int faceConfig = 0;
	bool hasChangeCubeFace = false;
	for (auto it = faceKeys.begin(); it < faceKeys.end(); ++it)
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
		_shader.setVec3("uColor", color);
		_shader.setInt("uFaceConfig", faceConfig);
		cubeColor = color;
	}

	// use textures
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
	{
		useTexture = !useTexture;	// toggle
		_shader.setBool("useTexture", useTexture);
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(static_cast<float>(yoffset));
}