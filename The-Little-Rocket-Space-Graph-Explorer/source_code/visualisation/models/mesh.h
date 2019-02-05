#pragma once
#ifdef _WIN32
	#define GLEW_STATIC
#endif
#include <GL\glew.h>
#include <vector>

#include "scene_object.h"
#include "vertex.h"
#include "texture.h"

class Mesh : public SceneObject
{
	friend class Model;

	GLuint EBO;
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	void setupDrawingDependencies();
	void drawObject() const override;
	
public:

	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures, const std::string& vertexPath, const std::string& fragmentPath);

};