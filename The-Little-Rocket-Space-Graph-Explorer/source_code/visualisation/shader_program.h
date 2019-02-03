#pragma once
#ifdef _WIN32
	#define GLEW_STATIC
#endif

#include <gl/glew.h>
#include <GLFW/glfw3.h>

class ShaderProgram
{
	GLuint ID;

public:

	ShaderProgram(const GLchar* vertexPath, const GLchar* fragmentPath);

	void use() const {
		glUseProgram(getProgramID());
	}

	GLuint getProgramID() const {
		return ID;
	}
};