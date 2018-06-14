#ifndef GAME_H
#define GAME_H
#include "window.h"
#include "LogManager.h"
enum class EGameState 
{
	E_START,
	E_PLAY,
	E_PAUSE,
	E_END
};

class game
{
private:
	window * gameWindow;
	LogManager* engineLog;

private:
	EGameState currentState;

public:
	// initialize Game parameters
	void init();

public:
	game(window* RenderWindow, LogManager* engineLog);
	~game();


public:
	void update(float deltaSeconds);
	void render();

public:
	EGameState getCurrentState() { return currentState; };
	void SetCurrentState(EGameState state);

private:
	void StartStateUpdate(float deltaSecondes);
	void PlayStateUpdate(float deltaSeconds);
	void PauseStateUpdate(float deltaSeconds);
	void EndStateUpdate(float deltaSeconds);

	void StartStateRender();
	void PlayStateRender();
	void PauseStateRender();
	void EndStateRender();
};
#endif

