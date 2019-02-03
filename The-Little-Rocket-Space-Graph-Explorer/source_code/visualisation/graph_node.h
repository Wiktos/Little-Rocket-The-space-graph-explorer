#pragma once
#include "scene_object.h"

class GraphNode final : public SceneObject
{
	std::vector<GLfloat> vertices;

	void drawObject() const {
		shader.use();
		glBindVertexArray(VAO);
		glDrawArrays(GL_POLYGON, 0, vertices.size());
		glBindVertexArray(0);
	}
	
public:

	GraphNode(ShaderProgram shader) : SceneObject(shader) {
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
	}
};