#include "camera.h"



camera::camera(vec3 camPos, vec3 camTarget, float fov, float width, float height, float nearz, float farz):
	baseCam(fov, width, height, nearz, farz)
{
	this->UpVector = vec3(0.0f, 1.0f, 0.0f);
	this->camPos = camPos;
	this->camTarget = camTarget;
	this->targetToPos = normalize(this->camPos - this->camTarget);
	this->camRight = normalize(cross(this->UpVector, this->targetToPos));
	this->camUp = cross(this->targetToPos, this->camRight);
	
}

camera::camera(vec3 camPos, vec3 camTarget, float left, float right, float bot, float top, float nearz, float farz):
	baseCam(left, right, bot, top, nearz, farz)
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
	mat4 view = mat4(1);
	view = glm::lookAt(camPos, camTarget, camUp);
	return view;
}

void camera::update(float deltaSec)
{
	// recalucate camera up vector;
	this->targetToPos = normalize(this->camPos - this->camTarget);
	this->camRight = normalize(cross(this->UpVector, this->targetToPos));
	this->camUp = cross(this->targetToPos, this->camRight);
}
