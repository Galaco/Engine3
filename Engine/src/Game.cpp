#include "Game.h"

#include <systems/SGraphics.h>
#include <systems/SAnimation.h>
#include <systems/SCollision.h>
#include <input/InputListener.h>

Game::Game(Engine& engine) : m_engine(engine){
	m_engine = engine;
}

Game::~Game(){
}

bool Game::initialise()
{
	SGraphics* graphics = new SGraphics();
	m_engine.RegisterSystem(graphics);
	m_engine.RegisterSystem(new SAnimation());
	m_engine.RegisterSystem(new SCollision());

	InputListener* listener = new InputListener();
	auto window = graphics->getCurrentWindow();
	listener->setWindowToListen(window);

	m_engine.RegisterInputListener(listener);


	m_engine.initialize();

	return true;
}

void Game::run()
{
	this->initialise();

	m_engine.start();
}