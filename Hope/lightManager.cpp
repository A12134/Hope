#include "lightManager.h"



lightManager::lightManager()
{
}


lightManager::~lightManager()
{
}

void lightManager::addNewSpotLight(spotLight * sl)
{
	mSpotLights.push_back(sl);
}

void lightManager::addNewSpotLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, vec3 direction, float cutoffangle)
{
	mSpotLights.push_back(
		new spotLight(
			position,
			ambient,
			diffuse,
			specular,
			direction,
			cutoffangle
		)
	);
}

void lightManager::addNewPointLight(pointLight * pl)
{
	mPointLights.push_back(pl);
}

void lightManager::addNewPointLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, float constant, float linear, float quadratic)
{
	mPointLights.push_back(
		new pointLight(
			position,
			ambient,
			diffuse,
			specular,
			constant,
			linear,
			quadratic
		)
	);
}

void lightManager::addNewDirectionalLight(directionalLight * dl)
{
	mDirectionLights.push_back(dl);
}

void lightManager::addNewDirectionalLight(vec3 direction, vec3 ambient, vec3 diffuse, vec3 specular)
{
	mDirectionLights.push_back(
		new directionalLight(
			direction,
			ambient,
			diffuse,
			specular
		)
	);
}
