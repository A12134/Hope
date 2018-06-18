/*Part of this code is adapt from https://learnopengl.com/Model-Loading/Model */

#ifndef MODEL_H
#define MODEL_H
#include "LogManager.h"
#include <vector>
#include "LODmesh.h"
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class model
{
private:
	std::vector<LODmesh*> meshes;
	std::string modelName;
	LogManager* engineLog;

public:
	model(const char* filePath, LogManager* engineLog);
	~model();

public:
	void render();

private:
	void loadModel(std::string);
	void processNode(aiNode* node, const aiScene* scene);
	LODmesh* processMesh(aiMesh* mesh, const aiScene* scene);
};
#endif

