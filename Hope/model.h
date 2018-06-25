/*Part of this code is adapt from https://learnopengl.com/Model-Loading/Model */

#ifndef MODEL_H
#define MODEL_H
#include "LogManager.h"
#include <vector>
//#include "LODmesh.h"
#include "mesh.h"
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "textureManager.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "camera.h"
#include "shaderProgram.h"

class model
{
private:
	//std::vector<LODmesh*> meshes;
	std::vector<std::vector<mesh*>> LODmeshes;
	std::vector<float> LODtracker;
	int LODIndexTracker;
	std::string modelName;
	LogManager* engineLog;
	//Material mmaterial;
	textureManager* texManager;
	Materials* modelMat;

public:
	model(textureManager* _textureManager, std::string materialName, LogManager* engineLog);
	~model();

public:
	void render(glm::vec3 pos, camera* cam, shaderProgram* sp, glm::mat4 model);

	// integraded with LOD functionality
	void addNewLevelLOD(const char* filePath, float maximumDistance);
	unsigned int getLODlevel() { return LODmeshes.size(); };

private:
	void loadModel(std::string);
	void processNode(aiNode* node, const aiScene* scene, std::vector<mesh*>* tmpMeshes);
	mesh* processMesh(aiMesh* mesh, const aiScene* scene);
//	void loadMaterialTextures(aiMaterial * mat, aiTextureType type, E_TEXTURE_TYPE T_type, Material* materials);
};
#endif

