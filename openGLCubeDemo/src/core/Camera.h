#pragma once
#include "../util/Math.h"

class Vertex;
class Shaders;

class Camera
{
public:
	Camera() {}
	~Camera() {}
	Vector3 m_Position; //World coordinate
	Vector3 m_Target; //World coordinate
	Vector3 m_Up;
	Matrix m_ViewMatrix;

	void Init(const Vector3& v3);

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
};