#pragma once
#ifdef _WIN32
	#define GLEW_STATIC
#endif
#include <GL\glew.h>

#include <string>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "scene_object.h"

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
};

struct Texture {
	aiString path; 
	unsigned int id;
	std::string type;
};

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