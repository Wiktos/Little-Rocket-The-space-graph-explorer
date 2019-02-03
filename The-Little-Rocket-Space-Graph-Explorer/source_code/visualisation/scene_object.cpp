#include "scene_object.h"

SceneObject::SceneObject(const std::string& vertexPath, const std::string& fragmentPath) : shader(vertexPath.c_str(), fragmentPath.c_str())
{}

void SceneObject::draw() const {
	shader.use();
	shader.setMat4("model", model);
	shader.setMat4("view", view);
	shader.setMat4("projection", projection);
	drawObject();
	glUseProgram(0);
}

void SceneObject::rotate(float angle, glm::vec3 axis) {
	model = glm::rotate(model, glm::radians(angle), axis);
}

void SceneObject::translate(glm::vec3 vec) {
	model = glm::translate(model, vec);
}

void SceneObject::scale(glm::vec3 vec) {
	model = glm::scale(model, vec);
}

void SceneObject::setViewMatrix(glm::mat4 view) const {
	this->view = view;
}

void SceneObject::setProjectionMatrix(glm::mat4 projection) const {
	this->projection = projection;
}

SceneObject::~SceneObject() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}