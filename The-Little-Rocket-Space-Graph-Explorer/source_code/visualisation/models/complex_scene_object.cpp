#include "complex_scene_object.h"

void ComplexSceneObject::pushBackObject(std::shared_ptr<SceneObject> obj) {
	objects.push_back(obj);
}

std::shared_ptr<SceneObject> ComplexSceneObject::getObject(int idx) {
	return objects[idx];
}

std::vector<std::shared_ptr<SceneObject>> ComplexSceneObject::getObjects() {
	return objects;
}

void ComplexSceneObject::rotate(float angle, glm::vec3 axis) {
	for (auto obj : objects) {
		obj->rotate(angle, axis);
	}
}

void ComplexSceneObject::translate(glm::vec3 vec) {
	for (auto obj : objects) {
		obj->translate(vec);
	}
}

void ComplexSceneObject::scale(glm::vec3 vec) {
	for (auto obj : objects) {
		obj->scale(vec);
	}
}