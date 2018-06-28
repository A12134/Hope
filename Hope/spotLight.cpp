#include "spotLight.h"

spotLight::spotLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, vec3 direction, float cutoffangle)
{
	param.position = position;
	param.ambient = ambient;
	param.diffuse = diffuse;
	param.specular = specular;
	param.direction = direction;
	param.cutoffAngle = cutoffangle;
}

spotLight::~spotLight()
{
}
