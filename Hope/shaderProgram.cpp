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

void shaderProgram::setUniform1f(const char * var, float f1)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform1f(loc, f1);
}

void shaderProgram::setUniform2f(const char * var, float f1, float f2)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform2f(loc, f1, f2);
}

void shaderProgram::setUniform3f(const char * var, float f1, float f2, float f3)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform3f(loc, f1, f2, f3);
}

void shaderProgram::setUniform4f(const char * var, float f1, float f2, float f3, float f4)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform4f(loc, f1, f2, f3, f4);
}

void shaderProgram::setUniform1i(const char * var, int i1)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform1i(loc, i1);
}

void shaderProgram::setUniform2i(const char * var, int i1, int i2)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform2i(loc, i1, i2);
}

void shaderProgram::setUniform3i(const char * var, int i1, int i2, int i3)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform3i(loc, i1, i2, i3);
}

void shaderProgram::setUniform4i(const char * var, int i1, int i2, int i3, int i4)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform4i(loc, i1, i2, i3, i4);
}

void shaderProgram::setUniform1ui(const char * var, unsigned int ui1)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform1ui(loc, ui1);
}

void shaderProgram::setUniform2ui(const char * var, unsigned int ui1, unsigned int ui2)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform2ui(loc, ui1, ui2);
}

void shaderProgram::setUniform3ui(const char * var, unsigned int ui1, unsigned int ui2, unsigned int ui3)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform3ui(loc, ui1, ui2, ui3);
}

void shaderProgram::setUniform4ui(const char * var, unsigned int ui1, unsigned int ui2, unsigned int ui3, unsigned int ui4)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform4ui(loc, ui1, ui2, ui3, ui4);
}

/*
void shaderProgram::setUniform1fv(const char * var, glm::vec1 vec1)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform1fv(loc, 1, glm::value_ptr(vec1));
}*/

void shaderProgram::setUniform2fv(const char * var, glm::vec2 vec2)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform2fv(loc, 1, glm::value_ptr(vec2));
}

void shaderProgram::setUniform3fv(const char * var, glm::vec3 vec3)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform3fv(loc, 1, glm::value_ptr(vec3));
}

void shaderProgram::setUniform4fv(const char * var, glm::vec4 vec4)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform4fv(loc, 1, glm::value_ptr(vec4));
}

/*
void shaderProgram::setUniform1iv(const char * var, glm::ivec1 ivec1)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform1iv(loc, 1, glm::value_ptr(ivec1));
}*/

void shaderProgram::setUniform2iv(const char * var, glm::ivec2 ivec2)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform2iv(loc, 1, glm::value_ptr(ivec2));
}

void shaderProgram::setUniform3iv(const char * var, glm::ivec3 ivec3)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform3iv(loc, 1, glm::value_ptr(ivec3));
}

void shaderProgram::setUniform4iv(const char * var, glm::ivec4 ivec4)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform4iv(loc, 1, glm::value_ptr(ivec4));
}

/*
void shaderProgram::setUniform1uiv(const char * var, glm::uvec1 uvec1)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform1uiv(loc, 1, glm::value_ptr(uvec1));
}*/

void shaderProgram::setUniform2uiv(const char * var, glm::uvec2 uvec2)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform2uiv(loc, 1, glm::value_ptr(uvec2));
}

void shaderProgram::setUniform3uiv(const char * var, glm::uvec3 uvec3)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform3uiv(loc, 1, glm::value_ptr(uvec3));
}

void shaderProgram::setUniform4uiv(const char * var, glm::uvec4 uvec4)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniform4uiv(loc, 1, glm::value_ptr(uvec4));
}

void shaderProgram::setUniformMatrix2x2fv(const char * var, glm::mat2 mat2, GLboolean transpose)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniformMatrix2fv(loc, 1, transpose, glm::value_ptr(mat2));
}

void shaderProgram::setUniformMatrix3x3fv(const char * var, glm::mat3 mat3, GLboolean transpose)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniformMatrix3fv(loc, 1, transpose, glm::value_ptr(mat3));
}

void shaderProgram::setUniformMatrix4x4fv(const char * var, glm::mat4 mat4, GLboolean transpose)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniformMatrix4fv(loc, 1, transpose, glm::value_ptr(mat4));
}

void shaderProgram::setUniformMatrix2x3fv(const char * var, glm::mat2x3 mat2x3, GLboolean transpose)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniformMatrix2x3fv(loc, 1, transpose, glm::value_ptr(mat2x3));
}

void shaderProgram::setUniformMatrix3x2fv(const char * var, glm::mat3x2 mat3x2, GLboolean transpose)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniformMatrix3x2fv(loc, 1, transpose, glm::value_ptr(mat3x2));
}

void shaderProgram::setUniformMatrix2x4fv(const char * var, glm::mat2x4 mat2x4, GLboolean transpose)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniformMatrix2x4fv(loc, 1, transpose, glm::value_ptr(mat2x4));
}

void shaderProgram::setUniformMatrix4x2fv(const char * var, glm::mat4x2 mat4x2, GLboolean transpose)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniformMatrix4x2fv(loc, 1, transpose, glm::value_ptr(mat4x2));
}

void shaderProgram::setUniformMatrix3x4fv(const char * var, glm::mat3x4 mat3x4, GLboolean transpose)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniformMatrix3x4fv(loc, 1, transpose, glm::value_ptr(mat3x4));
}

void shaderProgram::setUniformMatrix4x3fv(const char * var, glm::mat4x3 mat4x3, GLboolean transpose)
{
	GLint loc = glGetUniformLocation(this->programID, var);
	glUniformMatrix4x3fv(loc, 1, transpose, glm::value_ptr(mat4x3));
}