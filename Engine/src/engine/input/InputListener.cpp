#include "InputListener.h"

#include <GLFW/glfw3.h>
BaseWindow* IInputListener::m_window;

InputListener::InputListener(){
	m_window = nullptr;
}

InputListener::~InputListener(){
	m_window = nullptr;
}

void InputListener::mouseKeyCallback(int button, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT) Mouse::_LEFT = true; else
		if (button == GLFW_MOUSE_BUTTON_RIGHT) Mouse::_RIGHT = true;
	}
	else
	if (action == GLFW_RELEASE)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT) Mouse::_LEFT = false; else
		if (button == GLFW_MOUSE_BUTTON_RIGHT) Mouse::_RIGHT = false;
	}
}

void InputListener::keyCallback(int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		Keyboard::KEY_ESC = true;
	}
	else {
		if (key < 168)
			Keyboard::Keys[key+32] = true;
		switch(key)
		{ 
		case GLFW_KEY_UP:
			Keyboard::Keys[196] = true;
			break;
		case GLFW_KEY_DOWN:
			Keyboard::Keys[197] = true;
			break;
		case GLFW_KEY_LEFT:
			Keyboard::Keys[198] = true;
			break;
		case GLFW_KEY_RIGHT:
			Keyboard::Keys[199] = true;
			break;
		}
	}
	if (action == GLFW_RELEASE) {
		if (key < 168)
			Keyboard::Keys[key + 32] = false;
		switch(key)
		{
		case GLFW_KEY_ESCAPE:
			Keyboard::KEY_ESC = false;
			break;
		case GLFW_KEY_UP:
			Keyboard::Keys[196] = false;
			break;
		case GLFW_KEY_DOWN:
			Keyboard::Keys[197] = false;
			break;
		case GLFW_KEY_LEFT:
			Keyboard::Keys[198] = false;
			break;
		case GLFW_KEY_RIGHT:
			Keyboard::Keys[199] = false;
			break;
		}
	}
}

void InputListener::cursorCallback(double width, double height){
	glfwGetCursorPos(static_cast<GLFWwindow*>(m_window->getContext()), &Mouse::_X, &Mouse::_Y);

	// Reset mouse position for next frame

	if (Mouse::_LOCKED)
	{
		int w, h;
		glfwGetWindowSize(static_cast<GLFWwindow*>(m_window->getContext()), &w, &h);
		glfwSetCursorPos(static_cast<GLFWwindow*>(m_window->getContext()), w / 2, h / 2);
	}
}

void InputListener::pollEvents(){
	resetPoll();
	glfwPollEvents();
}

void InputListener::resetPoll(){
	if (Mouse::_LOCKED){
		Mouse::_X = Config::_WINDOWWIDTH / 2;
		Mouse::_Y = Config::_WINDOWHEIGHT / 2;
	}
}

void InputListener::setWindowToListen(BaseWindow* window)
{
	IInputListener::setWindowToListen(window);

	std::function<void(int, int, int, int)> kb = keyCallback;
	window->registerKeyEventCallback(kb);

	std::function<void(double, double)> mouseMove = cursorCallback;
	window->registerMouseMoveEventCallback(mouseMove);

	std::function<void(int, int, int)> mousePress = mouseKeyCallback;
	window->registerMousePressEventCallback(mousePress);

	Mouse::setWindow(static_cast<GLFWwindow*>(window->getContext()));
}