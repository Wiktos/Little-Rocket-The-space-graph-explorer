#include "scene_object.h"

SceneObject::SceneObject(const std::string& vertexPath, const std::string& fragmentPath) : shader(vertexPath.c_str(), fragmentPath.c_str())
{}

void SceneObject::draw() const {
	shader.use();
	drawObject();
	glUseProgram(0);
}

SceneObject::~SceneObject() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}