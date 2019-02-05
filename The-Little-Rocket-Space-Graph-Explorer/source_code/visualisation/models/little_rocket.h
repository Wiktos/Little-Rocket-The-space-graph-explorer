#pragma once

#include "model.h"

class LittleRocket : public Model
{
	void setAtStartingPosition();

public:

	LittleRocket(const std::string& path, const std::string& vertexPath, const std::string& fragmentPath); 
	LittleRocket(const LittleRocket&) = default;
	LittleRocket(LittleRocket&&) = default;

	LittleRocket& operator=(const LittleRocket&) = default;
	LittleRocket& operator=(LittleRocket&&) = default;

	~LittleRocket() = default;
};