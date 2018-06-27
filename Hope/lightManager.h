#ifndef LIGHT_MANAGER_H
#define LIGHT_MANAGER_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "spotLight.h"
#include "directionalLight.h"
#include "pointLight.h"
#include <vector>

class lightManager
{
private:
	std::vector<spotLight*> mSpotLights;
	std::vector<directionalLight*> mDirectionLights;
	std::vector<pointLight*> mPointLights;

public:
	lightManager();
	~lightManager();

public:
	// add light to light manager
	
	// spot light
	void addNewSpotLight(spotLight* sl);
	void addNewSpotLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, vec3 direction, float cutoffangle);

	// point light
	void addNewPointLight(pointLight* pl);
	void addNewPointLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, float constant, float linear, float quadratic);

	// directional light
	void addNewDirectionalLight(directionalLight* dl);
	void addNewDirectionalLight(vec3 direction, vec3 ambient, vec3 diffuse, vec3 specular);

public:
	// access to lights vectors
	std::vector<spotLight*>* getSpotLights() { return &mSpotLights; }
	std::vector<directionalLight*>* getDirectionalLights() { return &mDirectionLights; }
	std::vector<pointLight*>* getPointLights() { return &mPointLights; }
};
#endif

