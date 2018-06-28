#include "directionalLight.h"


directionalLight::directionalLight(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
{
	param.direction = direction;
	param.ambient = ambient;
	param.diffuse = diffuse;
	param.specular = specular;
}

directionalLight::~directionalLight()
{
}
