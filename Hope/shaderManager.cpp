#include "shaderManager.h"



shaderManager::shaderManager(LogManager* engineLog)
{
	this->engineLog = engineLog;
}


shaderManager::~shaderManager()
{
}

void shaderManager::createNewShader(const std::string vertexShaderSource, const std::string shaderName)
{
	shader* vertexShader = new shader(EShaderType::E_VERTEX_SHADER, GL_VERTEX_SHADER);
	vertexShader->loadShaderSource(vertexShaderSource);

	engineLog->writeLog("Linking shader program.\n");

	shaderProgram* thisProgram = new shaderProgram(shaderName, engineLog);
	thisProgram->linkShaders(vertexShader->getShader());

	shaderCollection->push_back(thisProgram);

	delete vertexShader;
	vertexShader = nullptr;

	thisProgram = nullptr;
}

void shaderManager::createNewShader(const std::string vertexShaderSource, const std::string fragmentShaderSource, const std::string shaderName)
{
	shader* vertexShader = new shader(EShaderType::E_VERTEX_SHADER, GL_VERTEX_SHADER);
	vertexShader->loadShaderSource(vertexShaderSource);

	shader* fragmentShader = new shader(EShaderType::E_FRAGMENT_SHADER, GL_FRAGMENT_SHADER);
	fragmentShader->loadShaderSource(fragmentShaderSource);

	engineLog->writeLog("Linking shader program.\n");

	shaderProgram* thisProgram = new shaderProgram(shaderName, engineLog);
	thisProgram->linkShaders(vertexShader->getShader(), fragmentShader->getShader());
	
	shaderCollection->push_back(thisProgram);

	delete vertexShader;
	vertexShader = nullptr;

	delete fragmentShader;
	fragmentShader = nullptr;

	thisProgram = nullptr;
}

void shaderManager::createNewShader(const std::string vertexShaderSource, const std::string fragmentShaderSource, const std::string geometryShaderSource, const std::string shaderName)
{
	shader* vertexShader = new shader(EShaderType::E_VERTEX_SHADER, GL_VERTEX_SHADER);
	vertexShader->loadShaderSource(vertexShaderSource);

	shader* fragmentShader = new shader(EShaderType::E_FRAGMENT_SHADER, GL_FRAGMENT_SHADER);
	fragmentShader->loadShaderSource(fragmentShaderSource);

	shader* geometryShader = new shader(EShaderType::E_GEOMETRY_SHADER, GL_GEOMETRY_SHADER);
	geometryShader->loadShaderSource(geometryShaderSource);

	engineLog->writeLog("Linking shader program.\n");

	shaderProgram* thisProgram = new shaderProgram(shaderName, engineLog);
	thisProgram->linkShaders(vertexShader->getShader(), fragmentShader->getShader(), geometryShader->getShader());

	shaderCollection->push_back(thisProgram);

	delete vertexShader;
	vertexShader = nullptr;

	delete fragmentShader;
	fragmentShader = nullptr;

	delete geometryShader;
	geometryShader = nullptr;

	thisProgram = nullptr;
}

shaderProgram * shaderManager::getShader(const std::string shaderName)
{
	// can implement as hash table to increase the efficiency
	for (unsigned int i = 0; i < shaderCollection->size(); i++)
	{
		if (shaderCollection->at(i)->matchName(shaderName))
		{
			return shaderCollection->at(i);
		}
	}
	engineLog->writeLog("Error: No shader found! shader name: " + shaderName + "\n");
	engineLog->errorExit();

	// dummy line, dont remove this
	return nullptr;
}
