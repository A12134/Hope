#include "game.h"
#include "model.h"

void game::init()
{
	//TODO initialize Game parameters
	initShaders();
	addShader();
	initTexture();
	initCam();
	initModel();

	currentState = EGameState::E_PLAY;
}

void game::initShaders()
{
	mShaderManager = new shaderManager(engineLog);
}

void game::initTexture()
{
	mTextureManager = new textureManager(engineLog);
}

void game::initCam()
{
	gameCam = new camera(
		glm::vec3(0.0f, -14.0f, -10.0f),	// camera position
		glm::vec3(0.0f, -45.0f, 0.0f),		// camera target
		30.0f,								// field of view angle in degrees
		1024.0f,							// width
		800.0f,								// height
		0.1f,								// near plane
		100.0f								// far plane
	);
}

void game::initModel()
{
	transformation transform;
	transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
	transform.rotation = 0.0f;
	transform.rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
	transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);

	model* nanoSuit = new model(mTextureManager, "NanoSuitMat", engineLog);
	nanoSuit->addNewLevelLOD("assets//nanosuit.obj", 1000);

	testModel = new NanoSuit(transform, mShaderManager->getShader("NanoSuitShader"), nanoSuit, engineLog);

}

void game::addShader()
{
	mShaderManager->createNewShader("vertexShader.glsl", "fragmentShader.glsl", "NanoSuitShader");
}

game::game(window * RenderWindow, LogManager* engineLog)
{
	this->engineLog = engineLog;
	gameWindow = RenderWindow;
}

game::~game()
{
	delete testModel;
	testModel = nullptr;

	delete gameCam;
	gameCam = nullptr;

	delete mTextureManager;
	mTextureManager = nullptr;

	delete mShaderManager;
	mShaderManager = nullptr;

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
	testModel->update(deltaSeconds);
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
	testModel->render(gameCam);
}

void game::PauseStateRender()
{
}

void game::EndStateRender()
{
}
