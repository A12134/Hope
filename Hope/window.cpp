#include "window.h"
#include <iostream>


window::window(int width, int height, const char * windowTitle, GLFWmonitor * moniter, GLFWwindow * share, LogManager* engineLog)
{
	this->engineLog = engineLog;

	w = glfwCreateWindow(width, height, windowTitle, moniter, share);
	
	if (w == nullptr) 
	{
		engineLog->writeLog("Create Window failed");
		engineLog->errorExit();
	}
}

window::~window()
{
	glfwDestroyWindow(w);
	w = nullptr;
	engineLog = nullptr;
}

void window::activateContext()
{
	if(glfwGetCurrentContext() != w)
		glfwMakeContextCurrent(w);
}

void window::createViewport(int x, int y, int _x, int _y)
{
	glViewport(x, y, _x, _y);
}

void window::enableDepthTest()
{
	activateContext();
	glEnable(GL_DEPTH_TEST);
}

void window::clearColor(float r, float g, float b, float a)
{
	activateContext();
	glClearColor(r, g, b, a);
}

void window::clearColor(glm::vec3 color, float alpha)
{
	activateContext();
	glClearColor(color.r, color.g, color.b, alpha);
}

void window::clearBuffers()
{
	activateContext();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
