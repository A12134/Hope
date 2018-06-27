#include "pointLight.h"
#include "gameObject.h"


pointLight::pointLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, float constant, float linear, float quadratic):
	gameObject(transformation(position, 0.0f, vec3(1.0f,1.0f,1.0f)), sp, debugmodel, engineLog)
{
	param.position = position;
	param.ambient = ambient;
	param.diffuse = diffuse;
	param.specular = specular;
	param.constant = constant;
	param.linear = linear;
	param.quadratic = quadratic;
}

pointLight::~pointLight()
{
}
