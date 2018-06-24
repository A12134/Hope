#include "glad\glad.h"
#include "GLFW\glfw3.h"
#include "window.h"
#include "game.h"
#include "ColorTable.h"
#include "LogManager.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
	glViewport(0, 0, width, height);
}

int main() 
{
	bool shouldExit = false;
	// init Log Manager
	LogManager* engineLog = new LogManager();

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	window* mainWindow = new window(1024, 800, "Main window", NULL, NULL, engineLog);
	mainWindow->activateContext();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		engineLog->writeLog("Failed to initialize GLAD proc. \n");
		engineLog->errorExit();
	}


	mainWindow->createViewport(0, 0, 1024, 800);
	mainWindow->enableDepthTest();

	// window resize callback function
	glfwSetFramebufferSizeCallback(glfwGetCurrentContext(), framebuffer_size_callback);

	game* mainGame = new game(mainWindow, engineLog);
	mainGame->init();

	float oldTimeSinceStart = 0;
	while (!glfwWindowShouldClose(mainWindow->getWindow()))
	{
		float timeSinceStart = (float)glfwGetTime();
		float deltaTime = timeSinceStart - oldTimeSinceStart;
		oldTimeSinceStart = timeSinceStart;
		mainWindow->clearColor(COLOR_WHITE * 0.8f, 1.0f);
		mainWindow->clearBuffers();

		// update function
		mainGame->update(deltaTime);
		// render function
		mainGame->render();

		// swap Buffers
		glfwSwapBuffers(mainWindow->getWindow());
		glfwPollEvents();
	}

	glfwTerminate();
	// destructor
	delete mainGame;
	mainGame = nullptr;
	delete engineLog;
	engineLog = nullptr;
	return 0;
}