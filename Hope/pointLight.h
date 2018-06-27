#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H
#include "gameObject.h"
#include "shaderProgram.h"
#include "LogManager.h"
#include "model.h"
// The visualization debug is represented by 3d Model(gameObject class)
// Should upgraded to 2D rendering in the later version
using namespace glm;

struct PointLight
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float constant;
	float linear;
	float quadratic;
};

class pointLight :
	public gameObject
{
private:

	PointLight param;

public:
	static shaderProgram* sp;
	static LogManager* engineLog;
	static model* debugmodel;
public:
	pointLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, float constant, float linear, float quadratic);
	~pointLight();

	PointLight getParam() { return param; };
};
#endif
