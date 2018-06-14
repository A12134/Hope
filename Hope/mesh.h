#ifndef MESH_H
#define MESH_H
#include "shaderProgram.h"
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class mesh
{
private:
	shaderProgram * sp;
	
public:
	mesh();
	~mesh();
};
#endif

