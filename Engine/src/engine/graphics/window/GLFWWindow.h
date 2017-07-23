#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <graphics/BaseWindow.h>
#include <functional>

class Window : public BaseWindow
{
public:
	Window(int width, int height, bool fullscreen, char* windowName);

	void terminate();

	void swapBuffers() override;

	static void mouseKeyCallbackWrapper(GLFWwindow*, int, int, int);
	static void keyCallbackWrapper(GLFWwindow*, int, int, int, int);
	static void mouseMoveCallbackWrapper(GLFWwindow*, double, double);


	void registerMousePressEventCallback(std::function<void(int button, int action, int mods)>) override;
	void registerKeyEventCallback(std::function<void(int key, int scancode, int action, int mods)>) override;
	void registerMouseMoveEventCallback(std::function<void(double width, double height)>) override;

	bool isValid() override;
	void* getContext() override;

	void useCursorInput() override;

private:
	GLFWwindow* m_pWindow;

	static std::function<void(int key, int scancode, int action, int mods)> KeyEventCallbackFunc;
	static std::function<void(double width, double height)> MouseMoveEventCallbackFunc;
	static std::function<void(int button, int action, int mods)> MousePressEventCallbackFunc;
};

#endif