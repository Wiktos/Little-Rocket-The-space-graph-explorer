#include "scene_builder.h"

SceneBuilder::SceneBuilder(const GLuint width, const GLuint height, std::string title)
	: width(width), height(height), title(title)
{}

void SceneBuilder::setTitle(const std::string title) {
	this->title = title;
}

void SceneBuilder::setWidth(const GLuint width) {
	this->width = width;
}

void SceneBuilder::setHeight(const GLuint height) {
	this->height = height;
}

void SceneBuilder::setMonitor(GLFWmonitor* monitor) {
	this->monitor = monitor;
}

void SceneBuilder::setShare(GLFWwindow* share) {
	this->share = share;
}

void SceneBuilder::setFramebufferSizeCallback(GLFWframebuffersizefun cbfun) {
	this->cbfun = cbfun;
}

void SceneBuilder::addSceneHint(GLuint hint, GLuint value) {
	hints[hint] = value;
}

Scene SceneBuilder::createScene() {
	for (auto it : hints) {
		auto[hint, value] = it;
		glfwWindowHint(hint, value);
	}

	GLFWwindow* scenePtr = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!scenePtr) {
		throw std::exception("SceneBuilder : Fail to create GLFWwindow* while creating Scene");
	}

	if (cbfun) {
		glfwSetFramebufferSizeCallback(scenePtr, cbfun);
	}

	return Scene(scenePtr, width, height);
}