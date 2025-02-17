#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum CAMERA_MOVEMENT {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    ROTATE_UP,
    ROTATE_DOWN,
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = -15.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;


// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera
{
public:
    // constructor with vectors
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
    // constructor with scalar values
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

    void init(std::vector<float> projectionConfig, std::vector<float> cameraConfig);

    // processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void processDirectiveMovement(CAMERA_MOVEMENT direction, float deltaTime);

    // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void processMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);

    // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void processMouseScroll(float yoffset);

    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors();

    glm::mat4 getProjectionMat() const { return _projectionMat; }
    // returns the view matrix calculated using Euler Angles and the LookAt Matrix
    glm::mat4 getViewMat();
    void setPos(const glm::vec3& pos) { _position = pos; }
private:
    // camera Attributes
    glm::vec3 _position;
    glm::vec3 _front;
    glm::vec3 _up;
    glm::vec3 _right;
    glm::vec3 _worldUp;
    // euler Angles
    float _yaw;
    float _pitch;
    // camera options
    float _movementSpeed;
    float _mouseSensitivity;
    float _zoom;

    glm::mat4 _projectionMat{ 1.0f };
    glm::mat4 _viewMat{ 1.0f };
};
#endif