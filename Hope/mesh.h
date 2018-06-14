/*If not neccessary, do not directly reference this class. Use LOD mesh instead*/

#ifndef MESH_H
#define MESH_H

#include "glad\glad.h"
#include "GLFW\glfw3.h"
#include "shaderProgram.h"
#include "LogManager.h"
#include "meshDummy.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

using namespace glm;
using namespace std;

struct Vertex 
{
	vec3 Position;
	vec2 Normal;
	vec2 TexCoords;
};

struct Texture 
{
	unsigned int id;
	std::string type;
};

class mesh : private meshDummy
{
private:
	// Mesh Data
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;
	unsigned int VAO, VBO, EBO;


	// log pointer
	LogManager* engineLog;
public:
	mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures, LogManager* engineLog);
	~mesh();

public:
	void render(shaderProgram* shader, mat4 projection, mat4 model, mat4 view);

private:
	void setupMesh();

};

#endif
