#ifndef SPRITE_H
#define SPRITE_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "shaderProgram.h"
#include "textureManager.h"

class sprite
{
private:
	unsigned int VAO;
	unsigned int VBO;
	static const float quadPlane[];

protected:
	glm::vec3 position;
	glm::vec2 scale;
	float rotation;
	glm::vec3 color;

public:
	sprite();
	~sprite();

	void render(Material* mat, shaderProgram* sp);
};
#endif

