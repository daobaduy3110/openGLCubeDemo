#include "Camera.h"

void Camera::init(const Vector3 &v3)
{
	_viewMatrix.SetTranslation((Vector3(-v3.x, -v3.y, -v3.z)));
	_position = Vector3(v3);
	_target = _position + Vector3(0.0f, 0.0f, -1.0f);
	_up = Vector3(0.0f, 1.0f, 0.0f);
}

void Camera::MoveLeft(float speed, float deltaTime)
{
	Vector3 deltaMove = _up.Cross(_target-_position).Normalize() * (speed * deltaTime);
	_position += deltaMove;
	_target += deltaMove;
	Vector3 Zaxis = (_position - _target).Normalize(); 
	Vector3 Xaxis = _up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	Matrix rotate;
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	_viewMatrix = _viewMatrix.SetTranslation(-_position) * rotate;
}

void Camera::MoveRight(float speed, float deltaTime)
{
	Vector3 deltaMove = (_target-_position).Cross(_up).Normalize() * (speed * deltaTime);
	_position += deltaMove;
	_target += deltaMove;
	Vector3 Zaxis = (_position - _target).Normalize(); 
	Vector3 Xaxis = _up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	Matrix rotate;
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	_viewMatrix = _viewMatrix.SetTranslation(-_position) * rotate;
}

void Camera::MoveForward(float speed, float deltaTime)
{
	Vector3 deltaMove = (_target-_position).Normalize() * (speed * deltaTime);
	_position += deltaMove;
	_target += deltaMove;
	Vector3 Zaxis = (_position - _target).Normalize(); 
	Vector3 Xaxis = _up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	Matrix rotate;
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	_viewMatrix = _viewMatrix.SetTranslation(-_position) * rotate;
}

void Camera::MoveBackward(float speed, float deltaTime)
{
	Vector3 deltaMove = (_target-_position).Normalize() * (-speed * deltaTime);
	_position += deltaMove;
	_target += deltaMove;
	Vector3 Zaxis = (_position - _target).Normalize(); 
	Vector3 Xaxis = _up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	Matrix rotate;
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	_viewMatrix = _viewMatrix.SetTranslation(-_position) * rotate;
}

void Camera::MoveUp(float speed, float deltaTime)
{
	Vector3 deltaMove = _up.Normalize() * (speed * deltaTime);
	_position += deltaMove;
	_target += deltaMove;
	Vector3 Zaxis = (_position - _target).Normalize(); 
	Vector3 Xaxis = _up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	Matrix rotate;
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	_viewMatrix = _viewMatrix.SetTranslation(-_position) * rotate;
}

void Camera::MoveDown(float speed, float deltaTime)
{
	Vector3 deltaMove = _up.Normalize() * (-speed * deltaTime);
	_position += deltaMove;
	_target += deltaMove;
	Vector3 Zaxis = (_position - _target).Normalize(); 
	Vector3 Xaxis = _up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	Matrix rotate;
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	_viewMatrix = _viewMatrix.SetTranslation(-_position) * rotate;
}

void Camera::RotateUp(float speed, float deltaTime)
{
	Matrix worldMatrix;
	Matrix rotate;
	
	Vector3 Xaxis = _up.Cross(_position - _target).Normalize();
	rotate.SetRotationAngleAxis(speed*deltaTime,Xaxis.x,Xaxis.y,Xaxis.z);

	Vector4 localTarget = Vector4(_target - _position);
		
	localTarget = localTarget * rotate;
	Vector4 worldTarget = localTarget * worldMatrix.SetTranslation(_position);
	_target = Vector3(worldTarget.x,worldTarget.y,worldTarget.z);	
	
	Vector3 Zaxis = (_position - _target).Normalize(); 
	Xaxis = _up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	_viewMatrix = _viewMatrix.SetTranslation(-_position) * rotate;
}

void Camera::RotateDown(float speed, float deltaTime)
{
	Matrix worldMatrix;
	Matrix rotate;
	Vector3 Xaxis = _up.Cross(_position - _target).Normalize();

	rotate.SetRotationAngleAxis(-speed*deltaTime,Xaxis.x,Xaxis.y,Xaxis.z);

	Vector4 localTarget = Vector4(_target - _position);
		
	localTarget = localTarget * rotate;
	Vector4 worldTarget = localTarget * worldMatrix.SetTranslation(_position);
	_target = Vector3(worldTarget.x,worldTarget.y,worldTarget.z);	
	
	Vector3 Zaxis = (_position - _target).Normalize(); 
	Xaxis = _up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	_viewMatrix = _viewMatrix.SetTranslation(-_position) * rotate;
}

void Camera::RotateLeft(float speed, float deltaTime)
{
	Matrix worldMatrix;
	Matrix rotate;
	rotate.SetRotationY(speed*deltaTime);

	Vector4 localTarget = Vector4(_target - _position);
	localTarget = localTarget * rotate;
	Vector4 worldTarget = localTarget * worldMatrix.SetTranslation(_position);
	_target = Vector3(worldTarget.x,worldTarget.y,worldTarget.z);	

	Vector3 Zaxis = (_position - _target).Normalize(); 
	Vector3 Xaxis = _up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	_viewMatrix = _viewMatrix.SetTranslation(-_position) * rotate;
}

void Camera::RotateRight(float speed, float deltaTime)
{
	Matrix worldMatrix;
	Matrix rotate;
	rotate.SetRotationY(-speed*deltaTime);

	Vector4 localTarget = Vector4(_target - _position);
	localTarget = localTarget * rotate;
	Vector4 worldTarget = localTarget * worldMatrix.SetTranslation(_position);
	_target = Vector3(worldTarget.x,worldTarget.y,worldTarget.z);	
	
	Vector3 Zaxis = (_position - _target).Normalize(); 
	Vector3 Xaxis = _up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	_viewMatrix = _viewMatrix.SetTranslation(-_position) * rotate;
}	
