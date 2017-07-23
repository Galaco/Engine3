#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <graphics/BaseWindow.h>

class Window : BaseWindow
{
public:
	Window(int width, int height, bool fullscreen, char* windowName);

	void terminate();

	void swapBuffers() override;

	bool isValid() override;
	GLFWwindow* getContext();

	void useCursorInput() override;

private:
	GLFWwindow* m_pWindow;
};

#endif