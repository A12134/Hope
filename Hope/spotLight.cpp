#include "spotLight.h"
#include "gameObject.h"

spotLight::spotLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, vec3 direction, float cutoffangle):
	gameObject(transformation(position, 0.0f, vec3(1.0f,1.0f,1.0f)), sp, debugmodel, engineLog)
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
