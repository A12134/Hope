#ifndef CAMERA_H
#define CAMERA_H
#include "baseCam.h"

class camera :
	public baseCam
{
protected:
	vec3 camPos;
	vec3 camTarget;
	vec3 camUp;
	vec3 camRight;
	vec3 UpVector;
	vec3 targetToPos;
	
public:
	camera(vec3 camPos, vec3 camTarget,
		float fov, float width, float height, float nearz, float farz
	);
	camera(vec3 camPos, vec3 camTarget,
		float left, float right, float bot, float top, float nearz, float farz
	);
	~camera();

	mat4 getViewMatrix();

	virtual void update(float deltaSec);

	vec3 getCamPos() { return camPos; };
};
#endif

