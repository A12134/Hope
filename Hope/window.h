#ifndef WINDOW_H
#define WINDOW_H
#include "glad\glad.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"
#include "LogManager.h"

class window
{
private:
	GLFWwindow * w;
	LogManager* engineLog;

public:
	window(int width, int height, const char * windowTitle, GLFWmonitor* moniter, GLFWwindow* share, LogManager* engineLog);
	~window();

	void activateContext();

	GLFWwindow* getWindow() { return w; };

	void createViewport(int x, int y, int _x, int _y);

	void enableDepthTest();
	
	void clearColor(float r, float g, float b, float a);

	void clearColor(glm::vec3 color, float alpha);

	// clear depth buffer and color buffer
	void clearBuffers();
};
#endif
