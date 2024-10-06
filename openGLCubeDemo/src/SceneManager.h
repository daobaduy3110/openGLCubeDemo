#pragma once
#include "core/ISingleton.h"
#include "util/Math.h"
#include <vector>
#include <memory>
#include "core/Camera.h"
#include <string>

class Object;
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

	void drawScene();
	void updateScene(float deltaTime);
	void readKey(unsigned char key);
	void cleanUp();
private:
	std::vector<std::shared_ptr<Object>> _objs;
	GLuint obj_num = 0;

	Matrix _projectionMat;
	std::unique_ptr<Camera> _camera;
};