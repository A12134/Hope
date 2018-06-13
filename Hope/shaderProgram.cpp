#include "shaderProgram.h"
#include "glad\glad.h"
#include "GLFW\glfw3.h"


shaderProgram::shaderProgram(const std::string shaderName, LogManager* engineLog)
{
	this->shaderName = shaderName;
	this->engineLog = engineLog;
	this->programID = glCreateProgram();
}

shaderProgram::~shaderProgram()
{
}

void shaderProgram::linkShaders(unsigned int vertexShader, unsigned int fragmentShader, unsigned int geometryShader)
{
	glAttachShader(this->programID, vertexShader);
	glAttachShader(this->programID, fragmentShader);
	glAttachShader(this->programID, geometryShader);
	checkLinkShaders();
}

void shaderProgram::linkShaders(unsigned int vertexShader, unsigned int fragmentShader)
{
	glAttachShader(this->programID, vertexShader);
	glAttachShader(this->programID, fragmentShader);
	checkLinkShaders();
}

void shaderProgram::linkShaders(unsigned int vertexShader)
{
	glAttachShader(this->programID, vertexShader);
	checkLinkShaders();
}

void shaderProgram::checkLinkShaders()
{
	glLinkProgram(this->programID);
	int success;
	char InfoLog[512];
	glGetProgramiv(this->programID, GL_LINK_STATUS, &success);
	if (!success) 
	{
		glGetProgramInfoLog(this->programID, 512, NULL, InfoLog);
		engineLog->writeLog("Error: Shader program linking failed\n");
		engineLog->writeLog(InfoLog);
		engineLog->errorExit();
	}
}

void shaderProgram::useThis()
{
	glUseProgram(this->programID);
}
