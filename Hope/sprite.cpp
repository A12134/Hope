#include "sprite.h"


const float sprite::quadPlane[] =
{
	// pos		// Tex
	0.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f, 0.0f
};

sprite::sprite()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadPlane), quadPlane, GL_STATIC_DRAW);

	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}


sprite::~sprite()
{
}

void sprite::render(Material* mat, shaderProgram * sp)
{
	sp->useThis();
	glm::mat4 model = glm::mat4(1);
	model = glm::translate(model, position);
	model = glm::translate(model, glm::vec3(0.5f * scale.x, 0.5f * scale.y, 0.0f));
	model = glm::rotate(model, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f * scale.x, -0.5f * scale.y, 0.0f));
	model = glm::scale(model, glm::vec3(scale, 1.0f));

	// load in texture data
	for (unsigned int i = 0; i < mat->textureSet.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		std::string textureName = mat->textureSet.at(i).type;
		sp->setUniform1i(textureName.c_str(), i);
		glBindTexture(GL_TEXTURE_2D, mat->textureSet.at(i).id);
	}

	// load in matrix
	sp->setUniformMatrix4x4fv("transform", model, GL_FALSE);
	sp->setUniform3fv("color", color);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);

	glActiveTexture(GL_TEXTURE0);
}


