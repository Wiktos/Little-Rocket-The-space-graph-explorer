#pragma once
#ifdef _WIN32
	#define GLEW_STATIC
#endif

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <map>
#include "scene.h"

/*
	SceneBuilder class is responsible for building Scene object. Provides possibility to set diffrent creation option before calling createScene() method.
	To see default option of Scene that will be created without any settings see below in the private section of class.

	by Wiktor £azarski
*/
class SceneBuilder
{
	GLuint width = 800;
	GLuint height = 600;
	std::string title = "OpenGL Application";
	GLFWmonitor* monitor = nullptr;
	GLFWwindow* share = nullptr;
	GLFWframebuffersizefun cbfun = nullptr;
	std::map<GLuint, GLuint> hints = { { GLFW_VERSION_MAJOR, 4 }, {GLFW_VERSION_MINOR, 5} };

public :

	SceneBuilder(const GLuint width, const GLuint height, std::string title);
	SceneBuilder() = default;
	SceneBuilder(const SceneBuilder&) = default;
	SceneBuilder(SceneBuilder&&) = default;

	SceneBuilder& operator=(const SceneBuilder&) = delete;
	SceneBuilder& operator=(SceneBuilder&&) = delete;

	void setTitle(const std::string title);
	void setWidth(const GLuint width);
	void setHeight(const GLuint height);
	void setMonitor(GLFWmonitor* monitor);
	void setShare(GLFWwindow* share);
	void setFramebufferSizeCallback(GLFWframebuffersizefun cbfun);
	
	void addSceneHint(GLuint hint, GLuint value);

	Scene createScene();

	~SceneBuilder() = default;
};