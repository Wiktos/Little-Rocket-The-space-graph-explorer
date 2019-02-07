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
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

public:

	static void initGLFW();
	static void initGLEW();

	OpenGLApplication() = default;
	OpenGLApplication(const OpenGLApplication&) = default;
	OpenGLApplication(OpenGLApplication&&) = default;

	OpenGLApplication& operator=(const OpenGLApplication&) = default;
	OpenGLApplication& operator=(OpenGLApplication&&) = default;

	void makeContextCurrent(Scene& scene);

	GLboolean shouldAppBeClosed() const;
	void setApplicationShouldClose(GLboolean val);

	GLfloat delta() { return deltaTime; }
	void updateDeltaTime();

	~OpenGLApplication();
};