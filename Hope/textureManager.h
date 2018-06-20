
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include <vector>
#include <string>
#include "LogManager.h"
#include "texture.h"

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

std::string generateTexName(Material* mat, E_TEXTURE_TYPE type);

class textureManager
{
private:
	std::vector<Material*> Mats;
	LogManager* engineLog;

public:
	textureManager(LogManager* engineLog);
	~textureManager();

public:
	void createNewMaterial(std::string name);

	void addTexture(std::string materialName, const char* texturePath, E_TEXTURE_TYPE textureType, TEX_PARA warpMethod, TEX_PARA filterMethod);
	void addTexture(std::string materialName, const char* texturePath, E_TEXTURE_TYPE textureType, TEX_PARA warpMethod_s, TEX_PARA warpMethod_t, TEX_PARA filterMethod_min, TEX_PARA filterMethod_mag);
	void addMaterial(Material* mat);
	Material* findMaterial(std::string materialName);

private:
	
};
#endif