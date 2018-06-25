
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include <vector>
#include <string>
#include "LogManager.h"
#include "texture.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

enum class E_TEXTURE_TYPE
{
	DIFFUSE_MAP,
	OPACITY_MAP,
	BUMP_MAP,
	NORMAL_MAP,
	SPECULAR_MAP,
	AMBIENT_MAP
};

struct Texture
{
	unsigned int id;
	std::string type;
};
struct Material
{
	Material() : 
		diffuseNum(0), 
		opacityNum(0), 
		bumpNum(0), 
		normalNum(0), 
		specularNum(0),
		ambientNum(0)
	{};

	std::vector<Texture> textureSet;
	std::string name;
	unsigned int diffuseNum;
	unsigned int opacityNum;
	unsigned int bumpNum;
	unsigned int normalNum;
	unsigned int specularNum;
	unsigned int ambientNum;
};
struct Materials
{
	Materials(std::string _name) :
		name(_name)
	{};
	std::vector<Material> materialSet;
	std::string name;
};
std::string generateTexName(Material* mat, E_TEXTURE_TYPE type);

class textureManager
{
private:
	std::vector<Material*> Mats;
	std::vector<Materials> MatSets;
	LogManager* engineLog;

public:
	textureManager(LogManager* engineLog);
	~textureManager();

public:
	void createNewMaterial(std::string name);
	int createNewMaterialSet(std::string name);

	std::vector<Materials>* getMatSets() { return &MatSets; }
	Materials* getMatSet(int id) { return &MatSets.at(id); }

	std::vector<Texture>* getTextrueSet(int SetID, int MatID) { return &MatSets.at(SetID).materialSet.at(MatID).textureSet; }

	void loadTextureFromModel(std::string directory, std::string matName, Materials* set, aiMaterial * mat, aiTextureType type, E_TEXTURE_TYPE T_type, int* tmp);

	void addTexture(std::string materialName, const char* texturePath, E_TEXTURE_TYPE textureType, TEX_PARA warpMethod, TEX_PARA filterMethod);
	void addTexture(std::string materialName, const char* texturePath, E_TEXTURE_TYPE textureType, TEX_PARA warpMethod_s, TEX_PARA warpMethod_t, TEX_PARA filterMethod_min, TEX_PARA filterMethod_mag);

	Material* findMaterial(std::string materialName);
	Materials* findMatSet(std::string name);
	//model based texture storage
private:
	
};
#endif