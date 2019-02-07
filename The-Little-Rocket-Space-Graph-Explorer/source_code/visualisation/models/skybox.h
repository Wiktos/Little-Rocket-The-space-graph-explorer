#pragma once

#include <vector>
#include <string>
#include <SOIL.h>

#include "../models/scene_object.h"

/*
	Skybox class represents skybox of Scene object. MUST BE added to SceneObject vector of Scene class at the end.

	by Wiktor £azarski
*/
class Skybox : public SceneObject
{
	GLuint cubemapTexture;
	std::vector<std::string> faces {
									"right.jpg",
									"left.jpg",
									"top.jpg",
									"bottom.jpg",
									"back.jpg",
									"front.jpg" };

	std::vector<GLfloat> skyboxCoords;

	void drawObject() const;

	void setCoords();
	void setDrawingDependencies();
	void loadCubemap();

public:

	Skybox(const std::string& vertexPath, const std::string& fragmentPath);

	void draw() const override;

	virtual ~Skybox() = default;
};