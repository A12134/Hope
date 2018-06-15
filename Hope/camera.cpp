#include "camera.h"



camera::camera(vec3 camPos, vec3 camTarget, float fov, float width, float height, float near, float far):
	baseCam(fov, width, height, near, far)
{
	this->UpVector = vec3(0.0f, 1.0f, 0.0f);
	this->camPos = camPos;
	this->camTarget = camTarget;
	this->targetToPos = normalize(this->camPos - this->camTarget);
	this->camRight = normalize(cross(this->UpVector, this->targetToPos));
	this->camUp = cross(this->targetToPos, this->camRight);
	
}

camera::camera(vec3 camPos, vec3 camTarget, float left, float right, float bot, float top, float near, float far):
	baseCam(left, right, bot, top, near, far)
{
	this->UpVector = vec3(0.0f, 1.0f, 0.0f);
	this->camPos = camPos;
	this->camTarget = camTarget;
	this->targetToPos = normalize(this->camPos - this->camTarget);
	this->camRight = normalize(cross(this->UpVector, this->targetToPos));
	this->camUp = cross(this->targetToPos, this->camRight);
}

camera::~camera()
{
}

mat4 camera::getViewMatrix()
{
	return lookAt(camPos, camTarget, camUp);
}

void camera::update(float deltaSec)
{
	// recalucate camera up vector;
	this->targetToPos = normalize(this->camPos - this->camTarget);
	this->camRight = normalize(cross(this->UpVector, this->targetToPos));
	this->camUp = cross(this->targetToPos, this->camRight);
}
