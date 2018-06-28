#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

// The visualization debug is represented by 3d Model(gameObject class)
// Should upgraded to 2D rendering in the later version
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

struct SpotLight
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	vec3 direction;
	float cutoffAngle;
};

class spotLight
{
private:
	SpotLight param;


public:
	spotLight(vec3 position, vec3 ambient, vec3 diffuse, vec3 specular, vec3 direction, float cutoffangle);
	~spotLight();

	SpotLight getParam() { return param; };

	virtual void update(float deltaSec){};
};
#endif
