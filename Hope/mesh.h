#ifndef MESH_H
#define MESH_H

#include "glad\glad.h"
#include "GLFW\glfw3.h"
#include "shaderProgram.h"
#include "LogManager.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "textureManager.h"

using namespace glm;
using namespace std;

struct Vertex 
{
	vec3 Position;
	vec2 Normal;
	vec2 TexCoords;
};

class mesh
{
private:
	// Mesh Data
	vector<Vertex> vertices;
	vector<unsigned int> indices;

	unsigned int VAO, VBO, EBO;
	textureManager* texManager;
	int setID, matID;

	// log pointer
	LogManager* engineLog;
public:
	mesh(vector<Vertex> vertices, vector<unsigned int> indices, textureManager* texManager, int SetID, int matID, LogManager* engineLog);
	~mesh();

public:
	void render(shaderProgram* shader, mat4 projection, mat4 model, mat4 view);

private:
	void setupMesh();

};

#endif
