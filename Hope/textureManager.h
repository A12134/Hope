#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include <vector>
#include <string>
#include "LogManager.h"
#include "texture.h"

struct Texture
{
	unsigned int id;
	std::string type;
};
struct Material
{
	std::vector<Texture> textureSet;
	std::string name;
};
class textureManager
{
private:
	std::vector<Material> Mats;
	LogManager* engineLog;

public:
	textureManager(LogManager* engineLog);
	~textureManager();

public:
	void createNewMaterial(std::string name);

	void addTexture(std::string materialName, const char* texturePath, std::string textureType, TEX_PARA warpMethod, TEX_PARA filterMethod);
	void addTexture(std::string materialName, const char* texturePath, std::string textureType, TEX_PARA warpMethod_s, TEX_PARA warpMethod_t, TEX_PARA filterMethod_min, TEX_PARA filterMethod_mag);

	Material* findMaterial(std::string materialName);

private:
	bool textureExist(Material* mat, std::string textureType);
};
#endif