#pragma once
#include "model.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>
#include <iostream>
/*
	LittleRocket class represents main character of application.

	by Wiktor £azarski
*/
class LittleRocket : public Model
{
	glm::vec3 currPosition;
	glm::vec3 currFace;
	
	void setAtStartingPosition();

public:

	LittleRocket(const std::string& path, const std::string& vertexPath, const std::string& fragmentPath); 
	LittleRocket(const LittleRocket&) = default;
	LittleRocket(LittleRocket&&) = default;

	LittleRocket& operator=(const LittleRocket&) = default;
	LittleRocket& operator=(LittleRocket&&) = default;

	glm::vec3 position() const { return currPosition; }
	glm::vec3 face() const { return currFace; }
	void rotate(float angle, glm::vec3 axis) {
		Model::rotate(angle, axis);
		currFace = glm::rotate(currFace, glm::radians(angle), axis);
	}
	void translate(glm::vec3 vec) {
		Model::translate(vec);
	}

	~LittleRocket() = default;
};