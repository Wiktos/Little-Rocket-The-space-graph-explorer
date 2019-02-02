#include "openglapplication.h"

void OpenGLApplication::initGLFW() {
	if (!glfwInit()) {
		throw std::runtime_error("Fail to init GLFW");
	}
}

void OpenGLApplication::initGLEW() {
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		throw std::runtime_error("Fail to init GLEW");
	}
}

void OpenGLApplication::makeContextCurrent(Scene& scene) {
	glfwMakeContextCurrent(&scene);
}

GLboolean OpenGLApplication::shouldAppBeClosed() {
	return shouldBeClosed;
}

void OpenGLApplication::setApplicationShouldClose(GLboolean val) {
	shouldBeClosed = val;
}

OpenGLApplication::~OpenGLApplication() {
	glfwTerminate();
}