#pragma once
#ifdef _WIN32
	#define GLEW_STATIC
#endif

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <map>
#include "scene.h"

class SceneBuilder
{
public :

	SceneBuilder() = default;
	SceneBuilder(const SceneBuilder&) = default;
	SceneBuilder(const GLuint width, const GLuint height, std::string title) 
		: width(width), height(height), title(title)
	{}

	void setTitle(const std::string title);
	void setWidth(const GLuint width);
	void setHeight(const GLuint height);
	void setMonitor(GLFWmonitor* monitor);
	void setShare(GLFWwindow* share);
	void setFramebufferSizeCallback(GLFWframebuffersizefun cbfun);
	
	void addSceneHint(GLuint hint, GLuint value);

	Scene createScene();

	~SceneBuilder() = default;

private:

	GLuint width = 800;
	GLuint height = 600;
	std::string title = "OpenGL Application";
	GLFWmonitor* monitor = nullptr;
	GLFWwindow* share = nullptr;
	GLFWframebuffersizefun cbfun = nullptr;
	std::map<GLuint, GLuint> hints = { { GLFW_VERSION_MAJOR, 4 }, {GLFW_VERSION_MINOR, 5} };
};