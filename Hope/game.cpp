#include "game.h"
#include "model.h"


void game::init()
{
	//TODO initialize Game parameters
	lm = new lightManager();

	mesh::bingLightManager(lm);

	initShaders();
	addShader();
	initTexture();
	initCam();
	initModel();

	lm->addNewDirectionalLight(glm::vec3(-5.0f, -100.0f, -8.0f), COLOR_WHITE*0.04f, COLOR_WHITE*0.1f, COLOR_WHITE*0.8f);

	currentState = EGameState::E_START;
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
	// initilize Camera data
	gameCam = new camera(
		gameWindow,
		glm::vec3(0.0f, 10.0f, -10.0f),		// camera position
		glm::vec3(0.0f, 0.0f, 0.0f),		// camera target
		60.0f,								// field of view angle in degrees
		1024.0f,							// width
		800.0f,								// height
		0.1f,								// near plane
		100.0f								// far plane
		 );
}

void game::initModel()
{
	// initilize Model data
	transformation transform;
	transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
	transform.rotation = 0.0f;
	transform.rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
	transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
	
	model * nano = new model(mTextureManager, "NanoSuitMat", engineLog);
	nano->addNewLevelLOD("assets//nanosuit.obj", 1000);
	
	testModel = new nanoSuit(transform, mShaderManager->getShader("NanoSuitShader"), nano, engineLog);
}

void game::addShader()
{
	// adding shaders
	mShaderManager->createNewShader("vertexShader.glsl", "fragmentShader.glsl", "NanoSuitShader");
	mShaderManager->createNewShader("vertexShader.glsl", "spriteFragmentShader.glsl", "SpriteShader");
}

game::game(window * RenderWindow, LogManager* engineLog)
{
	this->engineLog = engineLog;
	gameWindow = RenderWindow;
}

game::~game()
{
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

void game::StartStateUpdate(float deltaSeconds)
{
	//testModel->update(deltaSeconds);
	gameCam->update(deltaSeconds);
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
	testModel->render(gameCam);
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
