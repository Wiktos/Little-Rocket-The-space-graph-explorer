#pragma once
#ifdef _WIN32
	#define GLEW_STATIC
#endif

#include <gl/glew.h>
#include <GLFW/glfw3.h>

/*
	ShaderProgram class is responsible for loading shaders codes from files, compiling and linking shaders.
	Provides also managment of using shader program in OpenGL application.

	by Wiktor £azarski
*/
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