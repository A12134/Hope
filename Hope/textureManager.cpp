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

void textureManager::addTexture(std::string materialName, const char * texturePath, std::string textureType, TEX_PARA warpMethod, TEX_PARA filterMethod)
{
	Material* mat = findMaterial(materialName);
	if (!mat) 
	{
		engineLog->writeLog("Error: material " + materialName + " does not exist!\n");
		engineLog->errorExit();
	}
	
	if (textureExist(mat, textureType)) 
	{
		engineLog->writeLog("Error: material " + materialName + " already has texture " + textureType + "\n");
		engineLog->errorExit();
	}

	texture* newTex = new texture(texturePath, warpMethod, filterMethod, engineLog);

	Texture newTexture;
	newTexture.id = newTex->getTexture();
	newTexture.type = textureType;

	delete newTex;
	newTex = nullptr;

	mat->textureSet.push_back(newTexture);
	
}

void textureManager::addTexture(std::string materialName, const char * texturePath, std::string textureType, TEX_PARA warpMethod_s, TEX_PARA warpMethod_t, TEX_PARA filterMethod_min, TEX_PARA filterMethod_mag)
{
	Material* mat = findMaterial(materialName);
	if (!mat)
	{
		engineLog->writeLog("Error: material " + materialName + " does not exist!\n");
		engineLog->errorExit();
	}

	if (textureExist(mat, textureType))
	{
		engineLog->writeLog("Error: material " + materialName + " already has texture " + textureType + "\n");
		engineLog->errorExit();
	}

	texture* newTex = new texture(texturePath, warpMethod_s, warpMethod_t, filterMethod_min, filterMethod_mag, engineLog);

	Texture newTexture;
	newTexture.id = newTex->getTexture();
	newTexture.type = textureType;

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

bool textureManager::textureExist(Material * mat, std::string textureType)
{
	for (unsigned int i = 0; i < mat->textureSet.size(); i++)
	{
		if (mat->textureSet.at(i).type == textureType) 
		{
			return true;
		}
	}
	return false;
}


