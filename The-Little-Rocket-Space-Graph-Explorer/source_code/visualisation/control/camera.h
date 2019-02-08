#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "camera_view_vectors.h"

/*
	Camera class represents camera of OpenGL application.

	by Wiktor £azarski
*/
class Camera
{
	static const float SPEED_MIN;

	CameraViewVectors viewVectors;
	float speed = 1.5f;

public:

	Camera() = default;
	Camera(CameraViewVectors vectors) {
		viewVectors = vectors;
	}
	Camera(const Camera&) = default;
	Camera(Camera&&) = default;

	Camera& operator=(const Camera&) = default;
	Camera& operator=(Camera&&) = default;

	glm::mat4 getViewMatrix() const {
		return glm::lookAt(viewVectors.cameraPos, viewVectors.cameraPos + viewVectors.cameraFront, viewVectors.cameraUp);
	}

	float getSpeed() const { return speed; }
	void increaseSpeed();
	void decreaseSpeed();

	void moveForward(float delta);
	void moveBackward(float delta);
	void moveLeft(float delta);
	void moveRight(float delta);

	glm::vec3 currentPostion() const { return viewVectors.cameraPos; }
	void setPosition(glm::vec3 newPos) { viewVectors.cameraPos = newPos; }

	~Camera() = default;
};