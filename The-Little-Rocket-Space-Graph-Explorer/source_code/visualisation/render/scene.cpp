#ifdef _WIN32
#define GLEW_STATIC
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "scene.h"

GLFWwindow* Scene::operator&() {
	return window;
}

void Scene::clearColor(const Color& col) const {
	glClearColor(col.r, col.g, col.b, col.a);
}

void Scene::drawObjects() const {
	float aspect = width / static_cast<GLfloat>(height);
	for (auto obj : objects) {
		obj->setViewMatrix(camera.getViewMatrix());
		obj->setProjectionMatrix(glm::perspective(glm::radians(45.f), aspect, 0.1f, 100.f));
		obj->draw();
	}
}

void Scene::clearBuffers(std::vector<GLenum> buffers) const {
	glEnable(GL_DEPTH_TEST);
	for (auto buf : buffers) {
		glClear(buf);
	}
	glEnable(0);
}

void Scene::swapBuffers() const {
	glfwSwapBuffers(window);
}

void Scene::attachObject(std::shared_ptr<SceneObject> object) {
	objects.push_back(object);
}

void Scene::attachObjects(std::vector<std::shared_ptr<SceneObject>> objects) {
	for (auto obj : objects) {
		this->objects.push_back(obj);
	}
}

void Scene::attachCamera(const Camera& camera) {
	this->camera = camera;
}