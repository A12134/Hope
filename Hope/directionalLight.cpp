#include "directionalLight.h"
#include "gameObject.h"


directionalLight::directionalLight(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular):
	gameObject(transformation(vec3(0.0f, 0.0f, 0.0f), 0.0f, vec3(1.0f,1.0f,1.0f)), sp, debugmodel, engineLog)
{
	param.direction = direction;
	param.ambient = ambient;
	param.diffuse = diffuse;
	param.specular = specular;
}

directionalLight::~directionalLight()
{
}
