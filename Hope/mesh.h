#ifndef MESH_H
#define MESH_H
#include "shaderProgram.h"
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	unsigned int id;
	std::string type;
};

class mesh
{
private:
	shaderProgram * sp;
	unsigned int VAO, VBO, EBO;

public:
	mesh();
	~mesh();
};
#endif

