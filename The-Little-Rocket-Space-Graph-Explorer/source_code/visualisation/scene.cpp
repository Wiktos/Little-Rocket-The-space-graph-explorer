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
	for (unsigned int i = 0; i < objects.size(); i++) {
		objects[i]->draw();
	}
}

void Scene::clearBuffers(std::vector<GLenum> buffers) const {
	for (auto buf : buffers) {
		glClear(buf);
	}
}

void Scene::swapBuffers() const {
	glfwSwapBuffers(window);
}

void Scene::attachObject(SceneObject* object) {
	objects.push_back(object);
}