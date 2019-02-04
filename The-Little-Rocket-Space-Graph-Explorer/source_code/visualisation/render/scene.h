#pragma once

#include <vector>
#include <memory>

#include "../models/scene_object.h"
#include "../control/camera.h"
#include "color.h"

/*
	Scene class represents render window of OpenGL application.

	by Wiktor £azarski
*/
class Scene
{
	friend class SceneBuilder;

	GLFWwindow *window;
	GLuint width, height;
	std::shared_ptr<Camera> camera;
	std::vector<std::shared_ptr<SceneObject>> objects;

	Scene(GLFWwindow *window, GLuint width, GLuint height) : window(window), width(width), height(height) 
	{
		camera = std::make_shared<Camera>(CameraViewVectors());
	}

public :
	
	Scene(const Scene&) = default;
	Scene(Scene&&) = default;

	Scene& operator=(const Scene&) = delete;
	Scene& operator=(Scene&&) = delete;

	GLFWwindow* operator&();

	void clearColor(const Color& col) const;
	void drawObjects() const;
	void clearBuffers(std::vector<GLenum> buffers) const;
	void swapBuffers() const;

	void attachObject(std::shared_ptr<SceneObject> object);
	void attachObjects(std::vector<std::shared_ptr<SceneObject>> objects);
	void attachCamera(std::shared_ptr<Camera> camera);

	std::shared_ptr<Camera> getCamera() { return camera; }

	~Scene() = default;
};