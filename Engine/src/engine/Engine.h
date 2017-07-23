/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Engine
Description: The core engine. Handles very low level functions such
			 as config loading, input handling & window creation.
*********************************************************************/
#ifndef ENGINE_H
#define ENGINE_H

#ifdef SFML_STATIC	//Allow SFML 2.1 to link statically on VS2013
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif

#include <vector>

#include <SFML/System.hpp>
#include <system/ISystem.h>
#include <input/IInputListener.h>

#include <system/System.h>

#include <filesystem/Config.h>
#include <core/Logger.h>

#include <scene/SceneManager.h>
#include <scene/states/SplashState.h>


class Engine {
public:
	Engine();
	~Engine();

	bool initialize();

	void start();

	void update();


	void RegisterSystem(ISystem* system);
	void RegisterInputListener(IInputListener* listener);

	
private:
	std::vector<ISystem*> m_systems;
	IInputListener* m_inputListener;

    Config  m_config;
	SceneManager m_sceneManager;

	double m_elapsedTime, m_frameTime;
	sf::Clock m_clock;

	bool m_isRunning;
};
#endif