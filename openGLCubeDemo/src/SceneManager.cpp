#include "SceneManager.h"
#include "core/Object.h"
#include "definitions.h"

void SceneManager::readFile(const std::string file)
{
	FILE* f = NULL;
	fopen_s(&f, file.c_str(), "r");
	if (f)
	{
		GLfloat prj_fov, prj_near, prj_far;
		fscanf_s(f, "PROJECTION %f %f %f\n", &prj_fov, &prj_near, &prj_far);
		_projectionMat.SetPerspective(prj_fov, WINDOW_WIDTH / WINDOW_HEIGHT, prj_near, prj_far);
		Vector3 v3;
		fscanf_s(f, "VIEW %f %f %f\n", &v3.x, &v3.y, &v3.z);
		_camera->init(v3);

		fscanf_s(f, "Objects %u\n", &obj_num);
		_objs.resize(obj_num);
		for (uint32_t i = 0; i < obj_num; i++)
		{
			uint32_t objectID = 0;;
			fscanf_s(f, "ID %u\n", &objectID);
			_objs[i] = std::shared_ptr<Object>(new Object(objectID));
			_objs[i]->readFile(f);
		}
		fclose(f);
	}
}

Object* SceneManager::getObjectByID(GLuint objectID)
{
	for (unsigned int i = 0; i < obj_num; i++)
	{
		if (_objs[i]->getID() == objectID)
			return _objs[i].get();
	}
	return 0;
}

void SceneManager::init()
{
	// setup vertex datas
	
	// load textures

	// compile shaders


}

void SceneManager::drawScene()
{
}

void SceneManager::updateScene(float deltaTime)
{
}

void SceneManager::readKey(unsigned char key)
{
}

void SceneManager::cleanUp()
{
}
