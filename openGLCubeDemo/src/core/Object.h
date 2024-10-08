#pragma once
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
	virtual void rotate(float angle, const glm::vec3& axis);

	Shader* getShader() { return _shader.get(); }
	glm::mat4 getModelMat() const { return _modelMat; }
	void checkAutoRotate();
	void updateFaceColor(glm::vec3 color, int32_t faceConfig);
	void toggleUseTexture();
	void toggleAutoRotate();
	void onMouseScroll(double yOffset);
private:
	GLuint _id;
	glm::mat4 _modelMat = glm::mat4(1.0f);
	glm::vec3 _position;
	glm::vec3 _rotation;
	glm::vec3 _scale;
	glm::vec3 _color;
	std::unique_ptr<Shader> _shader;	// assuming only 1 shader for each object
	glm::vec3 _cubeColor = glm::vec3(0.0f, 0.0f, 1.0f);
	bool _useTexture = false;
	bool _isAutoRotate = false;
	float _autoRotateSpeed = 0.1f;
};