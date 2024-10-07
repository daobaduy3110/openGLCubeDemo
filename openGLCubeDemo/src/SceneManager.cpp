#include "SceneManager.h"
#include "definitions.h"
#include <stb/stb_image.h>

void SceneManager::readFile(const std::string file)
{

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
	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);

	_objs.clear();
	_objs.push_back(std::unique_ptr<Object>(new Object()));

	// setup vertex data
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
}

void SceneManager::setupShaders()
{
	for (auto it = _objs.begin(); it != _objs.end(); ++it)
	{
		(*it)->setupShader();
	}
}

void SceneManager::drawScene()
{
}

void SceneManager::updateScene(float deltaTime)
{
}

void SceneManager::readKey(unsigned char key)
{
}

void SceneManager::cleanUp()
{
}
