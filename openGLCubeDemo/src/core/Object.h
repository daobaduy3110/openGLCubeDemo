#pragma once
#include "../util/Math.h"
#include <memory>
#include <vector>
#include "Shader.h"

class Vertex;
class Camera;

class Object
{
public:
	Object();
	Object(GLuint id) : _id(id) {};
	virtual ~Object();

	GLuint getID() { return _id; }
	void render();
	virtual void readFile(FILE*& f);
	virtual void setupVertexData();
	virtual void setupShader();
	virtual void passAdditionalUniforms();
	virtual void update();
	virtual void cleanUp();
private:
	GLuint _id;
	Matrix _modelMat;
	Vector3 _position;
	Vector3 _rotation;
	Vector3 _scale;
	std::unique_ptr<Shader> _shader;	// assuming only 1 shader for each object
	glm::vec3 _cubeColor = glm::vec3(0.0f, 0.0f, 1.0f);
	bool _useTexture = false;
	bool _isAutoRotate = false;
};