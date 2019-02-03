#pragma once

#include <vector>
#include <memory>

#include "scene_object.h"
#include "color.h"

class Scene
{
	friend class SceneBuilder;

	GLFWwindow *window;
	std::vector<SceneObject*> objects;

	Scene(GLFWwindow *window) : window(window)
	{}

public :
	
	Scene(const Scene&) = default;
	Scene& operator=(const Scene&) = delete;
	Scene& operator=(Scene&&) = delete;

	GLFWwindow* operator&();

	void clearColor(const Color& col) const;
	void drawObjects() const;
	void clearBuffers(std::vector<GLenum> buffers) const;
	void swapBuffers() const;

	void attachObject(SceneObject* object);

	~Scene() = default;
};