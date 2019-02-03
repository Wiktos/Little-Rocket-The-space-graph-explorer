#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "camera_view_vectors.h"

/*
	Camera class represents camera of OpenGL application.

	by Wiktor £azarski
*/
class Camera
{
	CameraViewVectors viewVectors;

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

	~Camera() = default;
};