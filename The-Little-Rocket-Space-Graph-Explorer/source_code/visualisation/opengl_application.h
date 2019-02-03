#pragma once
#ifdef _WIN32
	#define GLEW_STATIC
#endif

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "scene.h"

/*
	OpenGLApplication class provides management of OpenGL application, it's extensions and every other external libs that can be used in application.

	by Wiktor £azarski
*/
class OpenGLApplication
{
	GLboolean shouldBeClosed = GL_FALSE;

public:

	OpenGLApplication() = default;
	OpenGLApplication(const OpenGLApplication&) = default;
	OpenGLApplication& operator=(const OpenGLApplication&) = default;
	OpenGLApplication& operator=(OpenGLApplication&&) = default;
	
	static void initGLFW();
	static void initGLEW();

	void makeContextCurrent(Scene& scene);

	GLboolean shouldAppBeClosed();
	void setApplicationShouldClose(GLboolean val);

	~OpenGLApplication();
};