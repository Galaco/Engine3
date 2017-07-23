#include "Engine.h"

#define FRAMETIME 12 //works better than 0.01667?

Engine::Engine() {
	if (m_config.load()){
		Logger::log(SUCCESS, "Configuration: Loaded data/core/base.cfg");
	}
	else {
		Logger::log(WARNING, "Configuration: Failed to load 'data/core/base.cfg'. Using defaults.");
	}
}

Engine::~Engine(){
	for (std::vector<ISystem*>::iterator it = this->m_systems.begin(); it != this->m_systems.end(); ++it)
	{
		(*it)->Terminate();
	}
}

bool Engine::initialize(){
	Logger::log(INFO, "Engine start");

	for (std::vector<ISystem*>::iterator it = this->m_systems.begin(); it != this->m_systems.end(); ++it)
	{
		(*it)->Initialise();
	}

	//if(!m_pWindow->isValid()) return false;
	//m_pInput.initialize(m_pWindow->getContext());

	Logger::log(INFO, "Finished engine initialisations\n");


	//Run initialize script to create a game
	//LuaScript* l = m_sScript.createScript();
	//l->runFile("init.lua");
	//m_sScript.deleteScript(l);	//script no longer needed. Delete


	return true;
}

void Engine::update(){
	//Standard Update
	m_frameTime = static_cast<double>(m_clock.getElapsedTime().asMilliseconds());
	if (m_frameTime > FRAMETIME)	//Keeps framerate at/below threshold
	{
		m_frameTime /= 1000;		//frametime in milliseconds
		m_clock.restart();			//reset frametime

		//m_pInput.pollEvents();			//update core engine elements

		for (vector<ISystem*>::iterator it = this->m_systems.begin(); it != this->m_systems.end(); ++it)
		{
			(*it)->FixedUpdate((float)m_frameTime);
		}

		System::FixedUpdateRemoveMe();
	}

	//Fixed Update
	for (vector<ISystem*>::iterator it = this->m_systems.begin(); it != this->m_systems.end(); ++it)
	{
		(*it)->Update();
	}
}


void Engine::RegisterSystem(ISystem* system)
{
	this->m_systems.push_back(system);
}
