#include "model.h"



model::model(const char* filePath, textureManager* _textureManager, std::string materialName, LogManager* engineLog)
{
	this->engineLog = engineLog;
	this->texManager = _textureManager;
	mmaterial.name = materialName;
	//loadModel(filePath);
}

model::~model()
{
}

void model::addNewLevelLOD(const char * filePath, float maximumDistance)
{
	loadModel(filePath);
	float tmp = maximumDistance;
	for (unsigned int i = 0; i < LODtracker.size(); i++)
	{
		if (tmp < LODtracker.at(i))
		{
			tmp = LODtracker.at(i) + 0.1f;
			engineLog->writeLog("Warning: Level of detail does not assigned by proper ascending order, this may causing incorrect visual effect.\n");
		}
	}
	LODtracker.push_back(tmp);
}

void model::loadModel(std::string path)
{
	Assimp::Importer import;
	const aiScene * scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
	
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		engineLog->writeLog("Error: ASSIMP:: " + std::string(import.GetErrorString()) + "\n");
		engineLog->errorExit();
	}
	this->modelName = path.substr(0, path.find_last_of('/'));

	processNode(scene->mRootNode, scene);
}

void model::processNode(aiNode * node, const aiScene * scene)
{
	// process all the node's meshes (if any)
	std::vector<mesh*> tmpMeshes;
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
		tmpMeshes.push_back(processMesh(mesh, scene));
	}

	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene);
	}

	LODmeshes.push_back(tmpMeshes);
}

mesh* model::processMesh(aiMesh * mesh, const aiScene * scene)
{
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;

	// processing vertices, normals and texCoords
	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex vertex;

		// processing vertices
		glm::vec3 vector;
		vector.x = mesh->mVertices[i].x;
		vector.y = mesh->mVertices[i].y;
		vector.z = mesh->mVertices[i].z;
		vertex.Position = vector;
		
		// processing normals
		vector.x = mesh->mNormals[i].x;
		vector.y = mesh->mNormals[i].y;
		vector.z = mesh->mNormals[i].z;
		vertex.Normal = vector;

		// processing texture coords
		if (mesh->mTextureCoords[0])
		{
			glm::vec2 vec;
			vec.x = mesh->mTextureCoords[0][i].x;
			vec.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
		}
		else
		{
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);
		}

		vertices.push_back(vertex);
	}

	// processing indices
	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
		{
			indices.push_back(face.mIndices[j]);
		}
	}

	// TODO processing Materials
	if (mesh->mMaterialIndex >= 0)
	{
		
		aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
		// diffuse maps
		loadMaterialTextures(material, aiTextureType_DIFFUSE, E_TEXTURE_TYPE::DIFFUSE_MAP);
		// specular maps
		loadMaterialTextures(material, aiTextureType_SPECULAR, E_TEXTURE_TYPE::SPECULAR_MAP);
		// normal maps
		loadMaterialTextures(material, aiTextureType_NORMALS, E_TEXTURE_TYPE::NORMAL_MAP);
		// ambient maps
		loadMaterialTextures(material, aiTextureType_AMBIENT, E_TEXTURE_TYPE::AMBIENT_MAP);

		material->~aiMaterial();
		material = nullptr;
	}

	texManager->addMaterial(&mmaterial);

	class mesh* newMesh = new class mesh(&vertices, &indices, &(mmaterial.textureSet), engineLog);

	return newMesh;
	
}

void model::loadMaterialTextures(aiMaterial * mat, aiTextureType type, E_TEXTURE_TYPE t_type)
{
	vector<Texture> textures;
	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		Texture _texture;
		texture* tex = new texture(str.C_Str(), TEX_PARA::E_WRAP_REPEAT, TEX_PARA::E_FILTER_LINEAR_MIPMAP_LINEAR, engineLog);
		_texture.id = tex->getTexture();
		_texture.type = generateTexName(&mmaterial, t_type);
		mmaterial.textureSet.push_back(_texture);
	}
}
