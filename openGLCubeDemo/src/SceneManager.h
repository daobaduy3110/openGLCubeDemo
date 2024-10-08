#pragma once
#include "core/ISingleton.h"
#include <vector>
#include <memory>
#include "core/Camera.h"
#include "core/Object.h"
#include <GLFW/glfw3.h>

class SceneManager : public ISingleton<SceneManager>
{
public:
	SceneManager() {}
	virtual ~SceneManager() {}
	SceneManager(const SceneManager&) {}
	SceneManager& operator =(const SceneManager&) {}

	Camera* getCamera() { return _camera.get(); }

	void readFile(const std::string file);
	Object* getObjectByID(GLuint objectID);

	void init();
	void setupVertexData();
	void loadTextures();
	void setupShaders();
	void render(float deltaTime);
	void onInput(GLFWwindow* window);
	void onMouseMovement(float xOffset, float yOffset);
	void onMouseScroll(double yOffset);
	void updateScene(float deltaTime);
	void readKey(unsigned char key);
	void cleanUp();
private:
	GLuint _VAO = 0, _VBO = 0;
	GLuint _texture0 = 0;
	std::unique_ptr<Camera> _camera;
	std::vector<std::unique_ptr<Object>> _objs{};
	float _deltaTime = 0.0f;
	float _scrollSensitivity = 0.1f;
};

#define SCENE_MGR SceneManager::getInstance()