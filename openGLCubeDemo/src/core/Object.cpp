#include "Object.h"
#include "../SceneManager.h"
#include "../definitions.h"
#include <glm/gtc/matrix_transform.hpp>

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
