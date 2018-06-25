#include "camera.h"

double camera::mouseXNew = 0;
double camera::mouseYNew = 0;
bool camera::changeViewAngle = false;

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
	this->cameraSpeed = 5.0f;
	this->cameraSensitivity = 0.05f;
	this->yaw = 0.0f;
	this->pitch = 0.0f;

	// register camera's mouse callback function
	glfwSetCursorPosCallback(w->getWindow(), getMousePosition_CallBack);
	glfwSetMouseButtonCallback(w->getWindow(), getMouseButton_CallBack);
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
	this->cameraSpeed = 5.0f;
	this->cameraSensitivity = 0.05f;
	this->yaw = 0.0f;
	this->pitch = 0.0f;

	glfwSetCursorPosCallback(w->getWindow(), getMousePosition_CallBack);
	glfwSetMouseButtonCallback(w->getWindow(), getMouseButton_CallBack);
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
	inputController(deltaSec);
	//this->targetToPos = normalize(this->camPos - this->camFront);
	this->camRight = normalize(cross(this->camFront, vec3(0.0f, 1.0f, 0.0f)));
	this->camUp = normalize(cross(this->camRight, this->camFront));
	mouseXLast = camera::mouseXNew;
	mouseYLast = camera::mouseYNew;
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
	if (changeViewAngle)
	{
		double deltaMouseX = camera::mouseXNew - this->mouseXLast;
		double deltaMouseY = camera::mouseYNew - this->mouseYLast;

		deltaMouseX *= this->cameraSensitivity;
		deltaMouseY *= this->cameraSensitivity;

		this->yaw += deltaMouseX;
		this->pitch += deltaMouseY;

		if (this->pitch > 89.0f)
		{
			this->pitch = 89.0f;
		}
		if (this->pitch < -89.0f)
		{
			this->pitch = -89.0f;
		}

		this->camFront.x = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
		this->camFront.y = sin(glm::radians(pitch));
		this->camFront.z = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
		camFront = glm::normalize(camFront);
	}
}

void camera::getMousePosition_CallBack(GLFWwindow * window, double _mouseX, double _mouseY)
{
	camera::mouseXNew = _mouseX;
	camera::mouseYNew = _mouseY;
}

void camera::getMouseButton_CallBack(GLFWwindow * window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		camera::changeViewAngle = true;
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		camera::changeViewAngle = false;
	}
}
