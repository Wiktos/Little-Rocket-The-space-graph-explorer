#pragma once

class ShaderProgram
{
	GLuint ID;

public:

	ShaderProgram(const GLchar* vertexPath, const GLchar* fragmentPath);

	void use() const
	{
		glUseProgram(getProgramID());
	}

	GLuint getProgramID() const
	{
		return ID;
	}
};