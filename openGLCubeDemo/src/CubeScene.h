#pragma once
#include <memory>

class Camera;

class CubeScene
{
public:
	void parseConfig();
	Camera* getCamera() { return _camera.get(); }
private:
	std::unique_ptr<Camera> _camera;
};
