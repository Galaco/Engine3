#include "engine/Engine.h"

#include <systems/SGraphics.h>
#include <systems/SAnimation.h>
#include <systems/SCollision.h>
#include <input/InputListener.h>


int main()
{
	Engine engine;

	// Register systems
	SGraphics* graphics = new SGraphics();
	engine.RegisterSystem(graphics);
	engine.RegisterSystem(new SAnimation());
	engine.RegisterSystem(new SCollision());

	// Register input listener
	InputListener* listener = new InputListener();
	auto window = graphics->getCurrentWindow();
	listener->setWindowToListen(window);
	engine.RegisterInputListener(listener);


	// Initialise engine
	engine.initialize();

	// Start
	engine.start();

	return 0;
}
