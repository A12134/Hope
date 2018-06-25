#ifndef CAMERA_H
#define CAMERA_H
#include "baseCam.h"


class camera :
	public baseCam
{
private:
	float cameraSpeed;
	float cameraSensitivity;

	vec2 LastFrameMousePos;
	double mouseXLast, mouseYLast;

	static bool changeViewAngle;

	double yaw, pitch;
protected:
	vec3 camPos;
	vec3 camTarget;
	vec3 camUp;
	vec3 camRight;
	vec3 UpVector;
	vec3 targetToPos;
	vec3 camFront;
public:
	static double mouseXNew, mouseYNew;
public:
	camera(window* w, vec3 camPos, vec3 camTarget,
		float fov, float width, float height, float nearz, float farz
	);
	camera(window* w, vec3 camPos, vec3 camTarget,
		float left, float right, float bot, float top, float nearz, float farz
	);
	~camera();

	mat4 getViewMatrix();

	virtual void update(float deltaSec);

	vec3 getCamPos() { return camPos; };

private:
	void inputController(float deltaSec);

public:

	// callbacks 
	static void getMousePosition_CallBack(GLFWwindow* window, double _mouseX, double _mouseY);
	static void getMouseButton_CallBack(GLFWwindow* window, int button, int action, int mods);
};
#endif

