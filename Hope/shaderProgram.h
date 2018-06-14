#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H
#include <string>
#include "LogManager.h"

class shaderProgram
{
private:
	LogManager * engineLog;
	std::string shaderName;
	unsigned int programID;

public:
	shaderProgram(const std::string shaderName, LogManager* engineLog);
	~shaderProgram();

	void linkShaders(unsigned int vertexShader, unsigned int fragmentShader, unsigned int geometryShader);

	void linkShaders(unsigned int vertexShader, unsigned int fragmentShader);

	void linkShaders(unsigned int vertexShader);

	void checkLinkShaders();

	// use this shader program
	void useThis();

	// check if the name is same with the shader's name
	bool matchName(std::string name) { return name == shaderName; }

	unsigned int getID() { return programID; }
};
#endif

