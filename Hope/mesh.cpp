#include "mesh.h"
#include <iostream>


mesh::mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures, LogManager* engineLog)
{
	this->engineLog = engineLog;

	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	setupMesh();
}

mesh::~mesh()
{
}

void mesh::render(shaderProgram * shaderPro, mat4 projection, mat4 model, mat4 view)
{
	shaderPro->useThis();
	mat4 matrices = projection * view * model;
	
	// load in texture data
	for (unsigned int i = 0; i < textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		std::string textureName = textures.at(i).type;
		shaderPro->setUniform1i(textureName.c_str(), i);
		glBindTexture(GL_TEXTURE_2D, textures.at(i).id);
	}
	
	// load in overall matrix
	unsigned int transformationLoc = glGetUniformLocation(shaderPro->getID(), "transform");
	glUniformMatrix4fv(transformationLoc, 1, GL_FALSE, value_ptr(matrices));

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	// set back to default
	glActiveTexture(GL_TEXTURE0);
}

void mesh::setupMesh()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);


	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices.front(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices.front(), GL_STATIC_DRAW);

	// passing in vertex position to buffer
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);

	// passing in vertex normals to buffer
	
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
	glEnableVertexAttribArray(1);

	// passing in texture coords
	
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}
