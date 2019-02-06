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
	
	void setAtStartingPosition();

public:

	LittleRocket(const std::string& path, const std::string& vertexPath, const std::string& fragmentPath); 
	LittleRocket(const LittleRocket&) = default;
	LittleRocket(LittleRocket&&) = default;

	LittleRocket& operator=(const LittleRocket&) = default;
	LittleRocket& operator=(LittleRocket&&) = default;

	glm::vec3 position() const { return currPosition; }

	void translate(glm::vec3 vec);

	~LittleRocket() = default;
};