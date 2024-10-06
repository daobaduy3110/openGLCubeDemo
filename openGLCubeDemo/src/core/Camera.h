#pragma once
#include "../util/Math.h"

class Vertex;
class Shaders;

class Camera
{
public:
	Camera() {}
	~Camera() {}
	Vector3 getPosition() { return _position; }
	Vector3 getTarget() { return _target; }
	Vector3 getUpVector() { return _up; }
	Matrix getViewMatrix() { return _viewMatrix; }

	void init(const Vector3& v3);

	void MoveLeft(float speed, float deltaTime);
	void MoveRight(float speed, float deltaTime);
	void MoveForward(float speed, float deltaTime);
	void MoveBackward(float speed, float deltaTime);
	void MoveUp(float speed, float deltaTime);
	void MoveDown(float speed, float deltaTime);

	void RotateUp(float speed, float deltaTime);
	void RotateDown(float speed, float deltaTime);
	void RotateLeft(float speed, float deltaTime);
	void RotateRight(float speed, float deltaTime);

private:
	Vector3 _position; //World coordinate
	Vector3 _target; //World coordinate
	Vector3 _up;
	Matrix _viewMatrix;
};