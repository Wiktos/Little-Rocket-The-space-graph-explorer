#pragma once
#ifdef _WIN32
	#define GLEW_STATIC
#endif

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <map>
#include <functional>

/*
	SceneController class is responsible for controlling and reacting on every event that happens in the Scene to which such controller is attached.
	SceneController is implemented as scalable factory design pattern. 

	by Wiktor £azarski
*/
class SceneController
{
	typedef GLuint Key;
	typedef std::function<void()> CallbackFunction;

	std::map<Key, CallbackFunction> callbacks;
	GLFWwindow *scene;

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
};