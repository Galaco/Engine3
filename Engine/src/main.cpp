#include "engine/Engine.h"
#include "Game.h"


int main()
{
	Engine engine;

	Game game(engine);
	game.run();

	return 0;
}
