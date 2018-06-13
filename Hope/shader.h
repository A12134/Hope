#ifndef SHADER_H
#define SHADER_H

#include <string>
#include "glad\glad.h"
#include "GLFW\glfw3.h"

enum class EShaderType 
{
	E_VERTEX_SHADER,
	E_FRAGMENT_SHADER,
	E_GEOMETRY_SHADER
};

class shader
{
private:
	std::string shaderSource;
	unsigned int shaderAddress;
	EShaderType shaderType;

public:
	shader(EShaderType type, GLint ID);

	bool loadShaderSource(const std::string &filename);

	unsigned int getShader() { return shaderAddress; }

	~shader();
};
#endif

