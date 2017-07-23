#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <functional>

class BaseWindow
{
public:
	virtual bool isValid() = 0;
	virtual void useCursorInput() = 0;

	virtual void swapBuffers() = 0;

	virtual void* getContext() = 0;

	virtual void registerKeyEventCallback(std::function<void(int key, int scancode, int action, int mods)>) = 0;
	virtual void registerMouseMoveEventCallback(std::function<void(double width, double height)>) = 0;
	virtual void registerMousePressEventCallback(std::function<void(int button, int action, int mods)>) = 0;
};

#endif