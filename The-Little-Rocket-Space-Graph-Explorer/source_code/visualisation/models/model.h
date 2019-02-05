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

	Model(std::string const &path, const std::string& vertexPath, const std::string& fragmentPath) {
		loadModel(path);
	}

	std::weak_ptr<SceneObject> getObject(int idx) = delete;
	std::vector<std::shared_ptr<SceneObject>> getObject() {
		return getObjects();
	}

private:

	void loadModel(std::string const &path);
	void processNode(aiNode *node, const aiScene *scene);
	std::shared_ptr<Mesh> processMesh(aiMesh *mesh, const aiScene *scene);
	std::vector<Vertex> getMeshVertices(aiMesh* mesh);
	std::vector<unsigned int> getMeshIndices(aiMesh* mesh);
	std::vector<Texture> getMeshTextures(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
	unsigned int textureFromFile(const char *path, const std::string &directory);
};