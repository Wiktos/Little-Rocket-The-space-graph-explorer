#include "scene_controller.h"

void SceneController::registerControlMethod(const Key& key, const CallbackFunction& cbfun) {
	if (callbacks.find(key) != callbacks.end()) {
		throw std::exception("Callback to key already exist");
	}

	callbacks[key] = cbfun;
}

void SceneController::pollEvents() const {
	glfwPollEvents();
	for (auto cb : callbacks) {
		auto[key, cbfun] = cb;
		if (glfwGetKey(scene, key) == GLFW_PRESS) {
			cbfun();
		}
	}
}