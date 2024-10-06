#pragma once
#include "../util/Math.h"
#include <memory>
#include <vector>
#include "Shader.h"

class Vertex;
//class Texture;
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
	virtual void passAdditionalUniforms();
	virtual void update();
	virtual void cleanUp();
private:
	GLuint _id;
	Matrix _worldMatrix;
	Matrix _viewMatrix;
	Vector3 _position;
	Vector3 _rotation;
	Vector3 _scale;
	//std::vector<std::unique_ptr<Texture>> _textures;
	std::unique_ptr<Shader> _shader;
};