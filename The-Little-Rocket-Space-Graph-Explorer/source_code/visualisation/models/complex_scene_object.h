#pragma once
#include <vector>
#include "scene_object.h"

/*
	ComplexSceneObject class provides an interface for collection of SceneObject that should be treaten as one object.

	by Wiktor £azarski
*/
class ComplexSceneObject
{
	std::vector<std::shared_ptr<SceneObject>> objects;

public:

	ComplexSceneObject() = default;
	ComplexSceneObject(const ComplexSceneObject&) = default;
	ComplexSceneObject(ComplexSceneObject&&) = default;

	ComplexSceneObject& operator=(const ComplexSceneObject&) = default;
	ComplexSceneObject& operator=(ComplexSceneObject&&) = default;

	void pushBackObject(std::shared_ptr<SceneObject> obj);
	std::weak_ptr<SceneObject> getObject(int idx);
	std::vector<std::shared_ptr<SceneObject>> getObjects();

	void rotate(float angle, glm::vec3 axis);
	void translate(glm::vec3 vec);
	void scale(glm::vec3 vec);
};