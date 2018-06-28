#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

// The visualization debug is represented by 3d Model(gameObject class)
// Should upgraded to 2D rendering in the later version
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

struct DirectionalLight
{
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

class directionalLight
{
private:

	DirectionalLight param;


public:
	directionalLight(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	~directionalLight();

	DirectionalLight getParam() { return param; }

	virtual void update(float deltaSec){};
};
#endif

