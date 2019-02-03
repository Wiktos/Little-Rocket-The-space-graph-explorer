#pragma once
#ifdef _WIN32
	#define GLEW_STATIC
#endif

#include <gl/glew.h>
#include <GLFW/glfw3.h>

/*
	Color struct represents color in RGBA format.

	by Wiktor £azarski
*/
struct Color
{
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
};