#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H
#include "gameObject.h"
#include "shaderProgram.h"
#include "LogManager.h"
#include "model.h"

// The visualization debug is represented by 3d Model(gameObject class)
// Should upgraded to 2D rendering in the later version

using namespace glm;

struct DirectionalLight
{
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

class directionalLight:
	public gameObject
{
private:

	DirectionalLight param;

public:
	static shaderProgram* sp;
	static LogManager* engineLog;
	static model* debugmodel;

public:
	directionalLight(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	~directionalLight();

	DirectionalLight getParam() { return param; }

	virtual void update(float deltaSec) override {};
};
#endif

