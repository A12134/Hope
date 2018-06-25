#include "camera.h"



camera::camera(window* w, vec3 camPos, vec3 camTarget, float fov, float width, float height, float nearz, float farz):
	baseCam(w, fov, width, height, nearz, farz)
{
	this->UpVector = vec3(0.0f, 1.0f, 0.0f);
	this->camPos = camPos;
	this->camTarget = camTarget;
	this->targetToPos = normalize(this->camPos - this->camTarget);
	this->camRight = normalize(cross(this->UpVector, this->targetToPos));
	this->camUp = cross(this->targetToPos, this->camRight);
	this->camFront = vec3(0.0f, 0.0f, 1.0f);
	cameraSpeed = 5.0f;
	
}

camera::camera(window* w, vec3 camPos, vec3 camTarget, float left, float right, float bot, float top, float nearz, float farz):
	baseCam(w, left, right, bot, top, nearz, farz)
{
	this->UpVector = vec3(0.0f, 1.0f, 0.0f);
	this->camPos = camPos;
	this->camTarget = camTarget;
	this->targetToPos = normalize(this->camPos - this->camTarget);
	this->camRight = normalize(cross(this->UpVector, this->targetToPos));
	this->camUp = cross(this->targetToPos, this->camRight);
	this->camFront = vec3(0.0f, 0.0f, 1.0f);
	cameraSpeed = 5.0f;
}

camera::~camera()
{
}

mat4 camera::getViewMatrix()
{
	mat4 view = mat4(1);
	view = glm::lookAt(camPos, camPos + camFront, camUp);
	return view;
}

void camera::update(float deltaSec)
{
	// recalucate camera up vector;
//	this->targetToPos = normalize(this->camPos - this->camTarget);
//	this->camRight = normalize(cross(this->UpVector, this->targetToPos));
//	this->camUp = cross(this->targetToPos, this->camRight);
	inputController(deltaSec);
}

void camera::inputController(float deltaSec)
{
	if (glfwGetKey(w->getWindow(), GLFW_KEY_W))
	{
		camPos += camFront * cameraSpeed * deltaSec;
	}
	if (glfwGetKey(w->getWindow(), GLFW_KEY_S))
	{
		camPos -= camFront * cameraSpeed * deltaSec;
	}
	if (glfwGetKey(w->getWindow(), GLFW_KEY_D))
	{
		camPos += camRight * cameraSpeed * deltaSec;
	}
	if (glfwGetKey(w->getWindow(), GLFW_KEY_A))
	{
		camPos -= camRight * cameraSpeed * deltaSec;
	}
}
