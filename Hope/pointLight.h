#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

// The visualization debug is represented by 3d Model(gameObject class)
// Should upgraded to 2D rendering in the later version
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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

class pointLight
{
private:

	PointLight param;

public:
	pointLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, float constant, float linear, float quadratic);
	~pointLight();

	PointLight getParam() { return param; };

	virtual void update(float deltaSec) {};


};
#endif
