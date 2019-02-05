#pragma once
#include "model.h"

/*
	LittleRocket class represents main character of application.

	by Wiktor £azarski
*/
class LittleRocket : public Model
{
	void setAtStartingPosition();

public:
	glm::vec3 currPosition;
	glm::vec3 currFace;

	LittleRocket(const std::string& path, const std::string& vertexPath, const std::string& fragmentPath); 
	LittleRocket(const LittleRocket&) = default;
	LittleRocket(LittleRocket&&) = default;

	LittleRocket& operator=(const LittleRocket&) = default;
	LittleRocket& operator=(LittleRocket&&) = default;

	~LittleRocket() = default;
};