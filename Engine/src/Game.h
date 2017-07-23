/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Game
Description: Contains the main game loop. Responsible for System & 
			 script initialisations.
*********************************************************************/
#ifndef GAME_H
#define GAME_H

#include <map>

#include <Engine.h>

#include <SFML/System.hpp>

#include <system/ISystem.h>

#include <scene/SceneManager.h>
#include <scene/states/SplashState.h>

#include "systems/SGraphics.h"
#include "systems/SAnimation.h"
#include "systems/SCollision.h"


class Game {
public:
	Game(Engine&);
	~Game();

	bool initialise();

	void run();

	bool running();

	void update();

	static void close();

private:
	void handleInputs();
        
        
	static bool m_isRunning;
    double m_elapsedTime, m_frameTime;

	Engine& m_engine;
    sf::Clock m_clock;

	static SceneManager m_sceneManager;
};
#endif
