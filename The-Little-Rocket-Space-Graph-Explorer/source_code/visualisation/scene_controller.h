#pragma once
#ifdef _WIN32
	#define GLEW_STATIC
#endif

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <map>
#include <functional>

class SceneController
{
	typedef GLuint Key;
	typedef std::function<void()> CallbackFunction;

public :

	SceneController(GLFWwindow *scene) : scene(scene)
	{}
	SceneController(const SceneController&) = default;
	SceneController(SceneController&&) = default;

	SceneController& operator=(const SceneController&) = default;
	SceneController& operator=(SceneController&&) = default;

	void registerControlMethod(const Key& key, const CallbackFunction& cbfun);
	void pollEvents() const;

	~SceneController() = default;

private:

	std::map<Key, CallbackFunction> callbacks;
	GLFWwindow *scene;
};