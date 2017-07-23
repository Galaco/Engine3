#include "Engine.h"

#define FRAMETIME 12 //works better than 0.01667?

Engine::Engine() {
	if (m_config.load()){
		Logger::log(SUCCESS, "Configuration: Loaded data/core/base.cfg");
	}
	else {
		Logger::log(WARNING, "Configuration: Failed to load 'data/core/base.cfg'. Using defaults.");
	}
	m_elapsedTime = 0.f;
	m_isRunning = false;
}

Engine::~Engine(){
	for (std::vector<ISystem*>::iterator it = this->m_systems.begin(); it != this->m_systems.end(); ++it)
	{
		(*it)->Terminate();
	}
}

bool Engine::initialize(){
	Logger::log(INFO, "Engine start");

	m_sceneManager.initialize();

	//remove me
	SplashState* s = new SplashState;
	m_sceneManager.addState(s, "Splash");//Push splash to state manager

	Logger::log(INFO, "Finished engine initialisations\n");


	return true;
}

void Engine::start()
{
	m_isRunning = true;

	while (m_isRunning == true)
	{
		this->update();
	}
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
		m_sceneManager.update((float)m_frameTime); //Update scenes
	}

	//Fixed Update
	for (vector<ISystem*>::iterator it = this->m_systems.begin(); it != this->m_systems.end(); ++it)
	{
		(*it)->Update();
	}
}


void Engine::RegisterSystem(ISystem* system)
{
	system->Initialise();
	this->m_systems.push_back(system);
}



void Engine::RegisterInputListener(IInputListener* listener)
{
	m_inputListener = listener;
}
