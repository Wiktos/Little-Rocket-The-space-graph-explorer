#pragma once

#include <glm/glm.hpp>

struct CameraViewVectors {
	glm::vec3 cameraPos = { 0.f, 0.f, 2.f };
	glm::vec3 cameraFront = { 0.f, 0.f, -1.f };
	glm::vec3 cameraUp = { 0.f, 1.f, 0.f };
};