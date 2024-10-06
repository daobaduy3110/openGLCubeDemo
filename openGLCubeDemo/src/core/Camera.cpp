#include "Camera.h"

void Camera::Init(const Vector3 &v3)
{
	m_ViewMatrix.SetTranslation((Vector3(-v3.x, -v3.y, -v3.z)));
	m_Position = Vector3(v3);
	m_Target = m_Position + Vector3(0.0f, 0.0f, -1.0f);
	m_Up = Vector3(0.0f, 1.0f, 0.0f);
}

void Camera::MoveLeft(float speed, float deltaTime)
{
	Vector3 deltaMove = m_Up.Cross(m_Target-m_Position).Normalize() * (speed * deltaTime);
	m_Position += deltaMove;
	m_Target += deltaMove;
	Vector3 Zaxis = (m_Position - m_Target).Normalize(); 
	Vector3 Xaxis = m_Up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	Matrix rotate;
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	m_ViewMatrix = m_ViewMatrix.SetTranslation(-m_Position) * rotate;
}

void Camera::MoveRight(float speed, float deltaTime)
{
	Vector3 deltaMove = (m_Target-m_Position).Cross(m_Up).Normalize() * (speed * deltaTime);
	m_Position += deltaMove;
	m_Target += deltaMove;
	Vector3 Zaxis = (m_Position - m_Target).Normalize(); 
	Vector3 Xaxis = m_Up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	Matrix rotate;
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	m_ViewMatrix = m_ViewMatrix.SetTranslation(-m_Position) * rotate;
}

void Camera::MoveForward(float speed, float deltaTime)
{
	Vector3 deltaMove = (m_Target-m_Position).Normalize() * (speed * deltaTime);
	m_Position += deltaMove;
	m_Target += deltaMove;
	Vector3 Zaxis = (m_Position - m_Target).Normalize(); 
	Vector3 Xaxis = m_Up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	Matrix rotate;
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	m_ViewMatrix = m_ViewMatrix.SetTranslation(-m_Position) * rotate;
}

void Camera::MoveBackward(float speed, float deltaTime)
{
	Vector3 deltaMove = (m_Target-m_Position).Normalize() * (-speed * deltaTime);
	m_Position += deltaMove;
	m_Target += deltaMove;
	Vector3 Zaxis = (m_Position - m_Target).Normalize(); 
	Vector3 Xaxis = m_Up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	Matrix rotate;
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	m_ViewMatrix = m_ViewMatrix.SetTranslation(-m_Position) * rotate;
}

void Camera::MoveUp(float speed, float deltaTime)
{
	Vector3 deltaMove = m_Up.Normalize() * (speed * deltaTime);
	m_Position += deltaMove;
	m_Target += deltaMove;
	Vector3 Zaxis = (m_Position - m_Target).Normalize(); 
	Vector3 Xaxis = m_Up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	Matrix rotate;
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	m_ViewMatrix = m_ViewMatrix.SetTranslation(-m_Position) * rotate;
}

void Camera::MoveDown(float speed, float deltaTime)
{
	Vector3 deltaMove = m_Up.Normalize() * (-speed * deltaTime);
	m_Position += deltaMove;
	m_Target += deltaMove;
	Vector3 Zaxis = (m_Position - m_Target).Normalize(); 
	Vector3 Xaxis = m_Up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	Matrix rotate;
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	m_ViewMatrix = m_ViewMatrix.SetTranslation(-m_Position) * rotate;
}

void Camera::RotateUp(float speed, float deltaTime)
{
	Matrix worldMatrix;
	Matrix rotate;
	
	Vector3 Xaxis = m_Up.Cross(m_Position - m_Target).Normalize();
	rotate.SetRotationAngleAxis(speed*deltaTime,Xaxis.x,Xaxis.y,Xaxis.z);

	Vector4 localTarget = Vector4(m_Target - m_Position);
		
	localTarget = localTarget * rotate;
	Vector4 worldTarget = localTarget * worldMatrix.SetTranslation(m_Position);
	m_Target = Vector3(worldTarget.x,worldTarget.y,worldTarget.z);	
	
	Vector3 Zaxis = (m_Position - m_Target).Normalize(); 
	Xaxis = m_Up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	m_ViewMatrix = m_ViewMatrix.SetTranslation(-m_Position) * rotate;
}

void Camera::RotateDown(float speed, float deltaTime)
{
	Matrix worldMatrix;
	Matrix rotate;
	Vector3 Xaxis = m_Up.Cross(m_Position - m_Target).Normalize();

	rotate.SetRotationAngleAxis(-speed*deltaTime,Xaxis.x,Xaxis.y,Xaxis.z);

	Vector4 localTarget = Vector4(m_Target - m_Position);
		
	localTarget = localTarget * rotate;
	Vector4 worldTarget = localTarget * worldMatrix.SetTranslation(m_Position);
	m_Target = Vector3(worldTarget.x,worldTarget.y,worldTarget.z);	
	
	Vector3 Zaxis = (m_Position - m_Target).Normalize(); 
	Xaxis = m_Up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	m_ViewMatrix = m_ViewMatrix.SetTranslation(-m_Position) * rotate;
}

void Camera::RotateLeft(float speed, float deltaTime)
{
	Matrix worldMatrix;
	Matrix rotate;
	rotate.SetRotationY(speed*deltaTime);

	Vector4 localTarget = Vector4(m_Target - m_Position);
	localTarget = localTarget * rotate;
	Vector4 worldTarget = localTarget * worldMatrix.SetTranslation(m_Position);
	m_Target = Vector3(worldTarget.x,worldTarget.y,worldTarget.z);	

	Vector3 Zaxis = (m_Position - m_Target).Normalize(); 
	Vector3 Xaxis = m_Up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	m_ViewMatrix = m_ViewMatrix.SetTranslation(-m_Position) * rotate;
}

void Camera::RotateRight(float speed, float deltaTime)
{
	Matrix worldMatrix;
	Matrix rotate;
	rotate.SetRotationY(-speed*deltaTime);

	Vector4 localTarget = Vector4(m_Target - m_Position);
	localTarget = localTarget * rotate;
	Vector4 worldTarget = localTarget * worldMatrix.SetTranslation(m_Position);
	m_Target = Vector3(worldTarget.x,worldTarget.y,worldTarget.z);	
	
	Vector3 Zaxis = (m_Position - m_Target).Normalize(); 
	Vector3 Xaxis = m_Up.Cross(Zaxis).Normalize();
	Vector3 Yaxis = Zaxis.Cross(Xaxis).Normalize();
	
	rotate.m[0][0] = Xaxis.x;	rotate.m[0][1] = Yaxis.x;	rotate.m[0][2] = Zaxis.x;	rotate.m[0][3] = 0.0f;
	rotate.m[1][0] = Xaxis.y;	rotate.m[1][1] = Yaxis.y;	rotate.m[1][2] = Zaxis.y;	rotate.m[1][3] = 0.0f;
	rotate.m[2][0] = Xaxis.z;	rotate.m[2][1] = Yaxis.z;	rotate.m[2][2] = Zaxis.z;	rotate.m[2][3] = 0.0f;
	rotate.m[3][0] = 0.0f	;	rotate.m[3][1] = 0.0f	;	rotate.m[3][2] = 0.0f	;	rotate.m[3][3] = 1.0f;
				
	m_ViewMatrix = m_ViewMatrix.SetTranslation(-m_Position) * rotate;
}	
