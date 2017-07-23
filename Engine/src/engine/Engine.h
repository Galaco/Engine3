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
#include <system/System.h>

#include <core/helpers/Config.h>
#include <core/Input.h>
#include <core/Logger.h>


class Engine {
public:
	Engine();
	~Engine();

	bool initialize();

	void update();


	void RegisterSystem(ISystem* system);

	
private:
	std::vector<ISystem*> m_systems;

    Input m_pInput;

    Config  m_config;


	double m_elapsedTime, m_frameTime;
	sf::Clock m_clock;
};
#endif