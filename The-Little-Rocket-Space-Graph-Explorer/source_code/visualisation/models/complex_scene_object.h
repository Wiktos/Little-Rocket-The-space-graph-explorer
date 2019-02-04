#pragma once
#include <vector>
#include "scene_object.h"

class ComplexSceneObject
{
	std::vector<std::shared_ptr<SceneObject>> objects;

public:

	ComplexSceneObject() = default;
	ComplexSceneObject(const ComplexSceneObject&) = default;
	ComplexSceneObject(ComplexSceneObject&&) = default;

	ComplexSceneObject& operator=(const ComplexSceneObject&) = default;
	ComplexSceneObject& operator=(ComplexSceneObject&&) = default;

	void pushBackObject(std::shared_ptr<SceneObject> obj) {
		objects.push_back(obj);
	}

	std::weak_ptr<SceneObject> getObject(int idx) {
		return objects[idx];
	}

	std::vector<std::shared_ptr<SceneObject>> getObjects() {
		return objects;
	}
};