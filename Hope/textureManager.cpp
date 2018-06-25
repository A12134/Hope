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
		if (Mats.at(i)->name == name)
		{
			engineLog->writeLog("Warning: Material " + name + " already exist\n");
			return;
		}
	}

	Material newMaterial;
	newMaterial.name = name;
	Mats.push_back(&newMaterial);
}

Materials* textureManager::createNewMaterialSet(std::string name)
{
	for (unsigned int i = 0; i < MatSets.size(); i++)
	{
		if (MatSets.at(i).name == name)
		{
			engineLog->writeLog("Warning: Material " + name + " already exist\n");
			return &MatSets.at(i);
		}
	}
	MatSets.push_back(Materials(name));
	return &MatSets.back();
}

void textureManager::loadTextureFromModel(std::string directory, std::string matName, Materials * set, aiMaterial * mat, aiTextureType type, E_TEXTURE_TYPE t_type, Material* tmp)
{
	for (unsigned int i = 0; i < set->materialSet.size(); i++)
	{
		if (set->materialSet.at(i).name == matName)
		{
			tmp = &set->materialSet.at(i);
			break;
		}
	}
	
	if (!tmp)
	{
		set->materialSet.push_back(Material());
		tmp = &set->materialSet.back();
		tmp->name = matName;
	}

	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		Texture _texture;
		std::string filePath = directory + str.C_Str();
		texture* tex = new texture(filePath.c_str(), TEX_PARA::E_WRAP_REPEAT, TEX_PARA::E_FILTER_LINEAR_MIPMAP_LINEAR, engineLog);
		_texture.id = tex->getTexture();
		_texture.type = generateTexName(tmp, t_type);
		tmp->textureSet.push_back(_texture);
		delete tex;
		tex = nullptr;
	}
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
		if (Mats.at(i)->name == materialName)
		{
			return Mats.at(i);
		}
	}
	return nullptr;
}

Materials * textureManager::findMatSet(std::string name)
{
	for (unsigned int i = 0; i < MatSets.size(); i++)
	{
		if (MatSets.at(i).name == name)
		{
			return &MatSets.at(i);
		}
	}
	return nullptr;
	return nullptr;
}

std::string generateTexName(Material * mat, E_TEXTURE_TYPE type)
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
	case E_TEXTURE_TYPE::AMBIENT_MAP:
		TexName += "Ambient_" + std::to_string(mat->ambientNum++);
		break;
	default:
		break;
	}
	return TexName;
}



