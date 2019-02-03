#pragma once
#include "shader_program.h" 

class SceneObject
{
	virtual void drawObject() const = 0;

protected:

	GLuint VAO, VBO;
	ShaderProgram shader;

public :
	
	SceneObject(ShaderProgram shader) : shader(shader)
	{}

	void draw() const {
		/*
			TODO:
			- IF SHADERS OR TRANSFORMATION SPECIFIED PERFORM
		*/
		

		drawObject();
	}

	virtual ~SceneObject() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
};