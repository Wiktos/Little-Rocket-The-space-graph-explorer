#include "little_rocket.h"

LittleRocket::LittleRocket(const std::string& path, const std::string& vertexPath, const std::string& fragmentPath) : Model(path, vertexPath, fragmentPath) {
	setAtStartingPosition();
	currPosition = glm::vec3(0.f, 0.f, 0.f);
}

void LittleRocket::translate(glm::vec3 vec) {
	Model::translate(glm::vec3(vec.x * 200.f, vec.y, vec.z * -200.f));
	currPosition += vec;
}

void LittleRocket::setAtStartingPosition() {
	Model::translate(glm::vec3(0.0f, 0.5f, 0.5f));
	Model::rotate(-180.f, glm::vec3(1.0f, 0.0f, 0.0f));
	scale(glm::vec3(0.005f, 0.005f, 0.005f));
}
