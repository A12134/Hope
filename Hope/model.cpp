#include "model.h"



model::model(textureManager* _textureManager, std::string materialName, LogManager* engineLog)
{
	this->engineLog = engineLog;
	this->texManager = _textureManager;
	//mmaterial.name = materialName;
	//loadModel(filePath);
	LODIndexTracker = 0;
	modelMatID = this->texManager->createNewMaterialSet(materialName);
}

model::~model()
{
}

void model::render(glm::vec3 pos, camera * cam, shaderProgram * sp, glm::mat4 model)
{
	float distanceFromCam = glm::length(pos - cam->getCamPos());
	if (LODtracker.at(LODIndexTracker) < distanceFromCam)
	{
		LODIndexTracker++;
	}
	else if (LODIndexTracker > 0)
	{
		if (LODtracker.at(LODIndexTracker-1) > distanceFromCam)
		{
			LODIndexTracker--;
		}
	}
	
	for (unsigned int i = 0; i < LODmeshes.at(LODIndexTracker).size(); i++)
	{
		LODmeshes.at(LODIndexTracker).at(i)->render(sp, cam->getProjectionMatrix(), model, cam->getViewMatrix(), cam->getCamPos());
	}
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
	std::vector<mesh*> tmpMeshes;
	processNode(scene->mRootNode, scene, &tmpMeshes);
	LODmeshes.push_back(tmpMeshes);
}

void model::processNode(aiNode * node, const aiScene * scene, std::vector<mesh*>* tmpMeshes)
{
	// process all the node's meshes (if any)
	//std::vector<mesh*> tmpMeshes;
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
		tmpMeshes->push_back(processMesh(mesh, scene));
	}

	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene, tmpMeshes);
	}

}

mesh* model::processMesh(aiMesh * mesh, const aiScene * scene)
{
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<vec3> tangents;
	//vector<Texture> textures;

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

	// TODO calculate tangent and bitangent.
	// for each three indices to form a face
	for (unsigned int i = 0; i < indices.size(); i+=3)
	{
		// calculate edge1 and edge2
		vec3 pos1 = vertices.at(indices.at(i)).Position;
		vec3 pos2 = vertices.at(indices.at(i + 1)).Position;
		vec3 pos3 = vertices.at(indices.at(i + 2)).Position;

		vec3 edge1 = pos2 - pos1;
		vec3 edge2 = pos3 - pos1;

		// calculate deltaUV1 and deltaUV2
		vec2 uv1 = vertices.at(indices.at(i)).TexCoords;
		vec2 uv2 = vertices.at(indices.at(i + 1)).TexCoords;
		vec2 uv3 = vertices.at(indices.at(i + 2)).TexCoords;

		vec2 deltaUV1 = uv2 - uv1;
		vec2 deltaUV2 = uv3 - uv1;

		// calculate tangent and bitangent
		float f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

		vec3 tangent = vec3(1);
		tangent.x = f * (deltaUV2.y * edge1.x - deltaUV1.y*edge2.x);
		tangent.y = f * (deltaUV2.y * edge1.y - deltaUV1.y*edge2.y);
		tangent.z = f * (deltaUV2.y * edge1.z - deltaUV1.y*edge2.z);
		tangent = normalize(tangent);

		// push back tangent
		tangents.push_back(tangent);

		vec3 bitangent = vec3(1);
		bitangent.x = f * (deltaUV1.x * edge2.x - deltaUV2.x * edge1.x);
		bitangent.y = f * (deltaUV1.x * edge2.y - deltaUV2.x * edge1.y);
		bitangent.z = f * (deltaUV1.x * edge2.z - deltaUV2.x * edge1.z);
		bitangent = normalize(bitangent);

		// push back bitangent
		tangents.push_back(bitangent);
	}
	


	// TODO processing Materials
	int tmpID = -1;
	if (mesh->mMaterialIndex >= 0)
	{
		
		aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
		// diffuse maps
		texManager->loadTextureFromModel(
			modelName,						// directory of the texture
			mesh->mName.C_Str(),			// the name of the mesh
			texManager->getMatSet(modelMatID),						// materialSet
			material,						// aiMaterial
			aiTextureType_DIFFUSE,			// type of the texture used by ASSIMP
			E_TEXTURE_TYPE::DIFFUSE_MAP,	// type of the texture used by this Engine
			&tmpID								// material holder
		);
		//loadMaterialTextures(material, aiTextureType_DIFFUSE, E_TEXTURE_TYPE::DIFFUSE_MAP, &meshMats);

		// specular maps
		texManager->loadTextureFromModel(
			modelName,						// directory of the texture
			mesh->mName.C_Str(),			// the name of the mesh
			texManager->getMatSet(modelMatID),						// materialSet
			material,						// aiMaterial
			aiTextureType_SPECULAR,			// type of the texture used by ASSIMP
			E_TEXTURE_TYPE::SPECULAR_MAP,	// type of the texture used by this Engine
			&tmpID					// material holder
		);
		//loadMaterialTextures(material, aiTextureType_SPECULAR, E_TEXTURE_TYPE::SPECULAR_MAP, &meshMats);

		// normal maps
		texManager->loadTextureFromModel(
			modelName,						// directory of the texture
			mesh->mName.C_Str(),			// the name of the mesh
			texManager->getMatSet(modelMatID),						// materialSet
			material,						// aiMaterial
			aiTextureType_HEIGHT,			// type of the texture used by ASSIMP
			E_TEXTURE_TYPE::NORMAL_MAP,		// type of the texture used by this Engine
			&tmpID								// material holder
		);
		//loadMaterialTextures(material, aiTextureType_NORMALS, E_TEXTURE_TYPE::NORMAL_MAP, &meshMats);

		// ambient maps
		texManager->loadTextureFromModel(
			modelName,						// directory of the texture
			mesh->mName.C_Str(),			// the name of the mesh
			texManager->getMatSet(modelMatID),						// materialSet
			material,						// aiMaterial
			aiTextureType_AMBIENT,			// type of the texture used by ASSIMP
			E_TEXTURE_TYPE::AMBIENT_MAP,	// type of the texture used by this Engine
			&tmpID								// material holder
		);
		//loadMaterialTextures(material, aiTextureType_AMBIENT, E_TEXTURE_TYPE::AMBIENT_MAP, &meshMats);
	}

	//texManager->addMaterial(&mmaterial);

	 

	return new class mesh(vertices, indices, tangents, texManager, modelMatID, tmpID, engineLog);
	
}

/*
void model::loadMaterialTextures(aiMaterial * mat, aiTextureType type, E_TEXTURE_TYPE t_type, Material* materials)
{
	vector<Texture> textures;
	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		Texture _texture;
		std::string filePath = modelName + str.C_Str();
		texture* tex = new texture(filePath.c_str(), TEX_PARA::E_WRAP_REPEAT, TEX_PARA::E_FILTER_LINEAR_MIPMAP_LINEAR, engineLog);
		_texture.id = tex->getTexture();
		_texture.type = generateTexName(materials, t_type);
		materials->textureSet.push_back(_texture);
		//mmaterial.textureSet.push_back(_texture);
	}
}
*/