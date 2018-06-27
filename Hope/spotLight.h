#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H
#include "gameObject.h"
#include "shaderProgram.h"
#include "LogManager.h"
#include "model.h"

// The visualization debug is represented by 3d Model(gameObject class)
// Should upgraded to 2D rendering in the later version

struct SpotLight
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	vec3 direction;
	float cutoffAngle;
};

class spotLight:
	public gameObject
{
private:
	SpotLight param;

public:
	static shaderProgram* sp;
	static LogManager* engineLog;
	static model* debugmodel;

public:
	spotLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, vec3 direction, float cutoffangle);
	~spotLight();

	SpotLight getParam() { return param; };
};
#endif
