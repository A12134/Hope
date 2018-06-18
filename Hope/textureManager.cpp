#include "textureManager.h"


textureManager::textureManager(LogManager * engineLog)
{
	this->engineLog = engineLog;
}

textureManager::~textureManager()
{
}

void textureManager::createNewMaterial(std::string name)
{
	for (unsigned int i = 0; i < Mats.size(); i++)
	{
		if (Mats.at(i).name == name)
		{
			engineLog->writeLog("Warning: Material " + name + " already exist\n");
			return;
		}
	}

	Material newMaterial;
	newMaterial.name = name;
	Mats.push_back(newMaterial);
}

void textureManager::addTexture(std::string materialName, const char * texturePath, E_TEXTURE_TYPE textureType, TEX_PARA warpMethod, TEX_PARA filterMethod)
{
	Material* mat = findMaterial(materialName);
	if (!mat) 
	{
		engineLog->writeLog("Error: material " + materialName + " does not exist!\n");
		engineLog->errorExit();
	}

	texture* newTex = new texture(texturePath, warpMethod, filterMethod, engineLog);

	Texture newTexture;
	newTexture.id = newTex->getTexture();
	newTexture.type = generateTexName(mat, textureType);

	delete newTex;
	newTex = nullptr;

	mat->textureSet.push_back(newTexture);
	
}

void textureManager::addTexture(std::string materialName, const char * texturePath, E_TEXTURE_TYPE textureType, TEX_PARA warpMethod_s, TEX_PARA warpMethod_t, TEX_PARA filterMethod_min, TEX_PARA filterMethod_mag)
{
	Material* mat = findMaterial(materialName);
	if (!mat)
	{
		engineLog->writeLog("Error: material " + materialName + " does not exist!\n");
		engineLog->errorExit();
	}

	texture* newTex = new texture(texturePath, warpMethod_s, warpMethod_t, filterMethod_min, filterMethod_mag, engineLog);

	Texture newTexture;
	newTexture.id = newTex->getTexture();
	newTexture.type = generateTexName(mat, textureType);

	delete newTex;
	newTex = nullptr;

	mat->textureSet.push_back(newTexture);
}

Material * textureManager::findMaterial(std::string materialName)
{
	for (unsigned int i = 0; i < Mats.size(); i++)
	{
		if (Mats.at(i).name == materialName)
		{
			return &(Mats.at(i));
		}
	}
	return nullptr;
}

std::string textureManager::generateTexName(Material * mat, E_TEXTURE_TYPE type)
{
	std::string TexName;

	switch (type)
	{
	case E_TEXTURE_TYPE::DIFFUSE_MAP:
		TexName = "Diffuse_" + std::to_string(mat->diffuseNum++);
		break;
	case E_TEXTURE_TYPE::OPACITY_MAP:
		TexName += "Opacity_" + std::to_string(mat->opacityNum++);
		break;
	case E_TEXTURE_TYPE::BUMP_MAP:
		TexName += "Bump_" + std::to_string(mat->bumpNum++);
		break;
	case E_TEXTURE_TYPE::NORMAL_MAP:
		TexName += "Normal_" + std::to_string(mat->normalNum++);
		break;
	case E_TEXTURE_TYPE::SPECULAR_MAP:
		TexName += "Specular_" + std::to_string(mat->specularNum++);
		break;
	default:
		break;
	}
	return TexName;
}



