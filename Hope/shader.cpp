#include "shader.h"
#include <sstream>
#include <fstream>
#include <iostream>

shader::shader(EShaderType type, GLint ID)
{
	this->shaderType = type;
	this->shaderAddress = glCreateShader(ID);
}

bool shader::loadShaderSource(const std::string & filename)
{
	std::ifstream file;

	file.open(filename.c_str());

	if (!file.good()) 
	{
		std::cout << "cannot open shader file. ERROR_SHADER_FILESOURCE_INVALID" << std::endl;
		return false;
	}

	std::stringstream stream;

	stream << file.rdbuf();

	file.close();
	this->shaderSource = stream.str();

	const char *sourceChar = shaderSource.c_str();
	glShaderSource(shaderAddress, 1, &sourceChar, NULL);
	glCompileShader(shaderAddress);

	int success;
	char infoLog[512];
	glGetShaderiv(shaderAddress, GL_COMPILE_STATUS, &success);

	if(!success)
	{
		glGetShaderInfoLog(shaderAddress, 512, NULL, infoLog);
		std::cout << "ERROR::COMPILE::" << int(shaderType) << "::FAILED\n" << infoLog << std::endl;
		return false;
	}

	return true;
}

shader::~shader()
{
}
