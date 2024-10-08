#include "Object.h"
#include "../SceneManager.h"
#include "../definitions.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

Object::Object()
{
}

Object::~Object()
{
}

void Object::render()
{

}

void Object::readFile(FILE*& f)
{
}

void Object::setupVertexData()
{
	// Open the file Cube.txt
	std::ifstream inputFile(CUBE_MODEL_PATH);

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
	if (!inputFile) {
		std::cerr << "Error: Could not open the file." << std::endl;
	}
	else
	{
		std::string line;
		while (std::getline(inputFile, line)) {
			// Replace 'f' with empty string to avoid issues while parsing
			std::replace(line.begin(), line.end(), 'f', ' ');

			// Create a stringstream for parsing the line
			std::istringstream iss(line);

			float value;
			uint32_t idx = 0;
			while (iss >> value) {
				// Read float values and push them to the vector
				vertices[idx] = value;
				++idx;
			}
		}
	}
	// Close the file
	inputFile.close();

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// face id attribute
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

void Object::setupShader()
{
	// compile shaders
	_shader = std::unique_ptr<Shader>(new Shader(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH));

	_shader->use();
	_shader->setInt("texture0", 0);
	_shader->setInt("uFaceConfig", (1 << 6) - 1);	// set all faces
	_shader->setVec3("uColor", _cubeColor);
	_shader->setVec3("cubeColor", _cubeColor);
	_shader->setBool("useTexture", _useTexture);
}

void Object::passAdditionalUniforms()
{
}

void Object::update()
{
}

void Object::cleanUp()
{
	_shader->cleanUp();
}

void Object::rotate(float angle, const glm::vec3& axis)
{
	_modelMat = glm::rotate(_modelMat, glm::radians(angle), axis);
	_shader->setMat4("model", _modelMat);
}

void Object::checkAutoRotate()
{
	if (_isAutoRotate)
	{
		rotate(_autoRotateSpeed, _autoRotateAxis);
	}
}

void Object::updateFaceColor(glm::vec3 color, int32_t faceConfig)
{
	_shader->setVec3("uColor", color);
	_shader->setInt("uFaceConfig", faceConfig);
	_cubeColor = color;
}

void Object::toggleUseTexture()
{
	_useTexture = !_useTexture;
	_shader->setBool("useTexture", _useTexture);
}

void Object::toggleAutoRotate()
{
	_isAutoRotate = !_isAutoRotate;
}

void Object::onMouseScroll(double yOffset)
{
	if (_isAutoRotate)
	{
		_autoRotateSpeed += yOffset;
		_autoRotateSpeed = glm::clamp(_autoRotateSpeed, -1.0f, 1.0f);
	}
}
