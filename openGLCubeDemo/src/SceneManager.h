#pragma once
#include "core/ISingleton.h"
#include "util/Math.h"
#include <vector>
#include <memory>
#include "core/Camera.h"
#include <string>
#include "core/Object.h"

class SceneManager : public ISingleton<SceneManager>
{
public:
	SceneManager() {}
	virtual ~SceneManager() {}
	SceneManager(const SceneManager&) {}
	SceneManager& operator =(const SceneManager&) {}

	Camera* getCamera() { return _camera.get(); }
	Matrix getProjectionMatrix() { return _projectionMat; }

	void readFile(const std::string file);
	Object* getObjectByID(GLuint objectID);

	void init();
	void setupVertexData();
	void loadTextures();
	void setupShaders();
	void drawScene();
	void updateScene(float deltaTime);
	void readKey(unsigned char key);
	void cleanUp();
private:
	GLuint _VAO = 0, _VBO = 0;
	GLuint _texture0;
	Matrix _projectionMat;
	Matrix _viewMat;
	std::unique_ptr<Camera> _camera;
	std::vector<std::unique_ptr<Object>> _objs{};
};

#define SCENE_MGR SceneManager::getInstance()