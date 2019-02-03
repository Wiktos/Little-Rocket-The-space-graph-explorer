#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include <GL/glew.h>
#include "shader_program.h"

string readShaderCode(const GLchar* shaderPath) {
	ifstream shader_file;
	shader_file.exceptions(ifstream::badbit);

	shader_file.open(shaderPath);
	stringstream shader_stream;
	shader_stream << shader_file.rdbuf();
	shader_file.close();
	return shader_stream.str();
}

GLuint compileShader(const GLchar* shaderCode, GLenum shaderType) {
	GLuint shader_id = glCreateShader(shaderType);
	glShaderSource(shader_id, 1, &shaderCode, NULL);
	glCompileShader(shader_id);

	// Print compile errors if any
	GLint success = 0;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(shader_id, sizeof(infoLog), NULL, infoLog);
		string msg = string("Shader compilation: ") + infoLog;
		throw exception(msg.c_str());
	}
	return shader_id;
}

ShaderProgram::ShaderProgram(const GLchar* vertexPath, const GLchar* fragmentPath) {
	// prepare vertex and fragment shaders
	string vertex_code = readShaderCode(vertexPath);
	GLuint vertex_id = compileShader(vertex_code.c_str(), GL_VERTEX_SHADER);

	string fragment_code = readShaderCode(fragmentPath);
	GLuint fragment_id = compileShader(fragment_code.c_str(), GL_FRAGMENT_SHADER);

	// link shader program
	ID = glCreateProgram();
	glAttachShader(ID, vertex_id);
	glAttachShader(ID, fragment_id);
	glLinkProgram(ID);

	// Print linking errors if any
	GLint success;
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[512];
		glGetProgramInfoLog(ID, sizeof(infoLog), NULL, infoLog);
		string msg = string("Shader program linking: ") + infoLog;
		throw exception(msg.c_str());
	}

	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vertex_id);
	glDeleteShader(fragment_id);
}
