#include "game.h"



void game::init()
{
	//TODO initialize Game parameters
}

game::game(window * RenderWindow, LogManager* engineLog)
{
	this->engineLog = engineLog;
	gameWindow = RenderWindow;
}

game::~game()
{
	delete gameWindow;
	gameWindow = nullptr;
}

void game::update(float deltaSeconds)
{
	switch (currentState)
	{
	case EGameState::E_START:
		StartStateUpdate(deltaSeconds);
		break;

	case EGameState::E_PLAY:
		PlayStateUpdate(deltaSeconds);
		break;

	case EGameState::E_PAUSE:
		PauseStateUpdate(deltaSeconds);
		break;

	case EGameState::E_END:
		EndStateUpdate(deltaSeconds);
		break;

	default:
		break;
	}
}

void game::render()
{
	switch (currentState)
	{
	case EGameState::E_START:
		StartStateRender();
		break;
	case EGameState::E_PLAY:
		PlayStateRender();
		break;
	case EGameState::E_PAUSE:
		PauseStateRender();
		break;
	case EGameState::E_END:
		EndStateRender();
		break;
	default:
		break;
	}
}

void game::SetCurrentState(EGameState state)
{
	switch (state)
	{
	case EGameState::E_START:
		// insert any initalize code for enter the state
		break;
	case EGameState::E_PLAY:
		// insert any initalize code for enter the state
		break;
	case EGameState::E_PAUSE:
		// insert any initalize code for enter the state
		break;
	case EGameState::E_END:
		// insert any initalize code for enter the state
		break;
	default:
		break;
	}

	this->currentState = state;
}

void game::StartStateUpdate(float deltaSecondes)
{
}

void game::PlayStateUpdate(float deltaSeconds)
{
}

void game::PauseStateUpdate(float deltaSeconds)
{
}

void game::EndStateUpdate(float deltaSeconds)
{
}

void game::StartStateRender()
{
}

void game::PlayStateRender()
{
}

void game::PauseStateRender()
{
}

void game::EndStateRender()
{
}
