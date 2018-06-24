#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <string>
#include "LogManager.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

	// Shader communication interface
public:
	// floats
	void setUniform1f(const char* var, float f1);
	void setUniform2f(const char* var, float f1, float f2);
	void setUniform3f(const char* var, float f1, float f2, float f3);
	void setUniform4f(const char* var, float f1, float f2, float f3, float f4);

	// integers
	void setUniform1i(const char* var, int i1);
	void setUniform2i(const char* var, int i1, int i2);
	void setUniform3i(const char* var, int i1, int i2, int i3);
	void setUniform4i(const char* var, int i1, int i2, int i3, int i4);

	// unsigned integers
	void setUniform1ui(const char* var, unsigned int ui1);
	void setUniform2ui(const char* var, unsigned int ui1, unsigned int ui2);
	void setUniform3ui(const char* var, unsigned int ui1, unsigned int ui2, unsigned int ui3);
	void setUniform4ui(const char* var, unsigned int ui1, unsigned int ui2, unsigned int ui3, unsigned int ui4);

	// float vector
	//void setUniform1fv(const char* var, glm::vec1 vec1);
	void setUniform2fv(const char* var, glm::vec2 vec2);
	void setUniform3fv(const char* var, glm::vec3 vec3);
	void setUniform4fv(const char* var, glm::vec4 vec4);

	// integer vector
	//void setUniform1iv(const char* var, glm::ivec1 ivec1);
	void setUniform2iv(const char* var, glm::ivec2 ivec2);
	void setUniform3iv(const char* var, glm::ivec3 ivec3);
	void setUniform4iv(const char* var, glm::ivec4 ivec4);

	// unsigned integer vector
	//void setUniform1uiv(const char* var, glm::uvec1 uvec1);
	void setUniform2uiv(const char* var, glm::uvec2 uvec2);
	void setUniform3uiv(const char* var, glm::uvec3 uvec3);
	void setUniform4uiv(const char* var, glm::uvec4 uvec4);

	// float matrix
	void setUniformMatrix2x2fv(const char* var, glm::mat2 mat2, GLboolean transpose);
	void setUniformMatrix3x3fv(const char* var, glm::mat3 mat3, GLboolean transpose);
	void setUniformMatrix4x4fv(const char* var, glm::mat4 mat4, GLboolean transpose);
	void setUniformMatrix2x3fv(const char* var, glm::mat2x3 mat2x3, GLboolean transpose);
	void setUniformMatrix3x2fv(const char* var, glm::mat3x2 mat3x2, GLboolean transpose);
	void setUniformMatrix2x4fv(const char* var, glm::mat2x4 mat2x4, GLboolean transpose);
	void setUniformMatrix4x2fv(const char* var, glm::mat4x2 mat4x2, GLboolean transpose);
	void setUniformMatrix3x4fv(const char* var, glm::mat3x4 mat3x4, GLboolean transpose);
	void setUniformMatrix4x3fv(const char* var, glm::mat4x3 mat4x3, GLboolean transpose);
};
#endif

