#ifdef USE_GLFW
#include "GLFWWindow.h"
#include <stdexcept>

std::function<void(int key, int scancode, int action, int mods)> Window::KeyEventCallbackFunc;
std::function<void(double width, double height)> Window::MouseMoveEventCallbackFunc;
std::function<void(int button, int action, int mods)> Window::MousePressEventCallbackFunc;


Window::Window(int width, int height, bool fullscreen, char* windowName)
{
	glfwInit();

	GLFWmonitor* m = nullptr;
	if (fullscreen == true)
	{
		m = glfwGetPrimaryMonitor();
	}
	this->m_pWindow = glfwCreateWindow(width, height, windowName, m, nullptr);

	if (this->m_pWindow == nullptr) {
		glfwTerminate();
		exit(1);
	}
	glfwMakeContextCurrent(this->m_pWindow);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, false);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

	if (!gladLoadGL()) {
		fprintf(stderr, "Failed to initialize OpenGL context");
		exit(1);
	}
}

void* Window::getContext()
{
	return m_pWindow;
}


void Window::terminate()
{
	glfwSetWindowShouldClose(m_pWindow, GL_TRUE);
	glfwDestroyWindow(m_pWindow);
	glfwTerminate();
}

bool Window::isValid()
{
	return (glfwWindowShouldClose(m_pWindow) == 0);
}

void Window::useCursorInput()
{
	glfwSetInputMode(m_pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(m_pWindow);
}

void Window::registerKeyEventCallback(std::function<void(int key, int scancode, int action, int mods)> func)
{
	KeyEventCallbackFunc = func; 
	glfwSetKeyCallback(static_cast<GLFWwindow*>(this->getContext()), keyCallbackWrapper);
}

void Window::keyCallbackWrapper(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	KeyEventCallbackFunc(key, scancode, action, mods);
}

void Window::registerMouseMoveEventCallback(std::function<void(double width, double height)> func)
{
	MouseMoveEventCallbackFunc = func;
	glfwSetCursorPosCallback(static_cast<GLFWwindow*>(this->getContext()), mouseMoveCallbackWrapper);
}

void Window::mouseMoveCallbackWrapper(GLFWwindow* window, double width, double height)
{
	MouseMoveEventCallbackFunc(width, height);
}

void Window::registerMousePressEventCallback(std::function<void(int button, int action, int mods)> func)
{
	MousePressEventCallbackFunc = func;
	glfwSetMouseButtonCallback(static_cast<GLFWwindow*>(this->getContext()), mouseKeyCallbackWrapper);
}

void Window::mouseKeyCallbackWrapper(GLFWwindow* window, int button, int action, int mods)
{
	MousePressEventCallbackFunc(button, action, mods);
}

#endif