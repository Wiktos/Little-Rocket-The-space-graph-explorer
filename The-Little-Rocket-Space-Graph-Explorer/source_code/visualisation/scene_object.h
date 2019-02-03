#pragma once
#include "shader_program.h" 

/*
	SceneObject class provides an interface for every object that would like to be drawn in Scene.
	The method design pattern is used to release object from managing such things like using shader and applying transformations.

	by Wiktor £azarski
*/
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