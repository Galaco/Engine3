#include "Game.h"

#define FRAMETIME 12 //works better than 0.01667?


bool Game::m_isRunning;
SceneManager Game::m_sceneManager;

Game::Game(Engine& engine) : m_engine(engine){
	m_engine = engine;
	m_elapsedTime = 0.f;
}

Game::~Game(){
}

bool Game::initialise()
{
	m_engine.RegisterSystem(new SGraphics());
	m_engine.RegisterSystem(new SAnimation());
	m_engine.RegisterSystem(new SCollision());

	m_engine.initialize();


	m_sceneManager.initialize();

	SplashState* s = new SplashState;
	m_sceneManager.addState(s, "Splash");//Push splash to state manager

	m_isRunning = true;

	return true;
}

void Game::run()
{
	this->initialise();

	while (this->running() == true)
	{
		this->update();
	}
}

void Game::update(){
	m_engine.update();

	m_frameTime = static_cast<double>(m_clock.getElapsedTime().asMilliseconds());
	if (m_frameTime > FRAMETIME)	//Keeps framerate at/below threshold
	{	
		m_frameTime /= 1000;		//frametime in milliseconds
		m_clock.restart();			//reset frametime

		m_sceneManager.update((float)m_frameTime); //Update scenes
	}
}

bool Game::running()
{ 
    return m_isRunning; 
}

void Game::close()
{
	m_isRunning = false;
}