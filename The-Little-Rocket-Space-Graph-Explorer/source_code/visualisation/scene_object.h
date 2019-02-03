#pragma once
#include "shader_program.h" 

class SceneObject
{
	virtual void drawObject() const = 0;

protected:

	mutable GLuint VAO, VBO;
	mutable ShaderProgram shader;

public :
	
	SceneObject(const std::string& vertexPath, const std::string& fragmentPath) : shader(vertexPath.c_str(), fragmentPath.c_str())
	{}

	void draw() const {
		shader.use();
		drawObject();
		glUseProgram(0);
	}

	virtual ~SceneObject() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
};