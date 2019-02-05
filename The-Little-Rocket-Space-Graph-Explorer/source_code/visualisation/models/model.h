#pragma once
#include <vector>
#include <string>

#include "mesh.h"
#include "complex_scene_object.h"

class Model : public ComplexSceneObject
{
	std::vector<Texture> textures_loaded;
	std::string directory;
	const std::string vertexShaderCodePath;
	const std::string fragmentShaderCodePath;

public:

	Model(const std::string& path, const std::string& vertexPath, const std::string& fragmentPath);

	std::weak_ptr<SceneObject> getObject(int idx) = delete;
	std::vector<std::shared_ptr<SceneObject>> getObject() {
		return getObjects();
	}

private:

	void loadModel(const std::string& path);
	void processNode(aiNode* node, const aiScene* scene);
	void processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Vertex> getMeshVertices(aiMesh* mesh);
	std::vector<GLuint> getMeshIndices(aiMesh* mesh);
	std::vector<Texture> getMeshTextures(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	unsigned int textureFromFile(const char* path, const std::string& directory);
};