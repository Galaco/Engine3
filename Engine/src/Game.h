/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Game
Description: Contains the main game loop. Responsible for System & 
			 script initialisations.
*********************************************************************/
#ifndef GAME_H
#define GAME_H

#include <Engine.h>

class Game {
public:
	Game(Engine&);
	~Game();

	bool initialise();

	void run();

private:       
	Engine& m_engine;
};
#endif