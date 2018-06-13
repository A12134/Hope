#ifndef SHADER_MANAGER
#define SHADER_MANAGER
#include "shaderProgram.h"
#include "shader.h"
#include "LogManager.h"
#include <vector>

class shaderManager
{
private:
	std::vector<shaderProgram*>* shaderCollection;
	LogManager* engineLog;

public:
	shaderManager(LogManager* engineLog);
	~shaderManager();

	// create a new shader program with single vertex shader
	void createNewShader(const std::string vertexShaderSource, const std::string shaderName);
	// create a new shader program with vertex shader and fragment shader
	void createNewShader(const std::string vertexShaderSource, const std::string fragmentShaderSource, const std::string shaderName);
	// create a new shader program with vertex shader, fragment shader and geometry shader
	void createNewShader(const std::string vertexShaderSource, const std::string fragmentShaderSource, const std::string geometryShaderSource, const std::string shaderName);

	// @return: shaderProgram pointer
	// should implemented with hash table
	shaderProgram* getShader(const std::string shaderName);
};
#endif


