#include "little_rocket.h"

void LittleRocket::setAtStartingPosition() {
	translate(glm::vec3(0.0f, 0.5f, 0.5f));
	rotate(-180.f, glm::vec3(1.0f, 0.0f, 0.0f));
	scale(glm::vec3(0.006f, 0.006f, 0.006f));
}

LittleRocket::LittleRocket(const std::string& path, const std::string& vertexPath, const std::string& fragmentPath) : Model(path, vertexPath, fragmentPath) {
	setAtStartingPosition();
}