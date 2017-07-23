/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Input
Description: Responsible for obtaining Input data, and, where relevant
			 passing it to the Keyboard. Should always be static.
*********************************************************************/
#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H

#include <core/Logger.h>
#include <input/IInputListener.h>
#include <graphics/BaseWindow.h>

#include <filesystem/Config.h>
#include <input/Keyboard.h>
#include <input/Mouse.h>


class InputListener : public IInputListener {
public:
	InputListener();
	~InputListener();

	static void keyCallback(int, int, int, int);
	static void mouseKeyCallback(int, int, int);
	static void cursorCallback(double, double);
	static void windowsizeCallback(GLFWwindow*, int, int);


	void setWindowToListen(BaseWindow* window);

	void pollEvents() override;

private:
	void resetPoll() override;

	Config      m_config;
};
#endif
