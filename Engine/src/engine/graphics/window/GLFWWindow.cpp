#ifdef USE_GLFW
#include "GLFWWindow.h"
#include <stdexcept>

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

GLFWwindow* Window::getContext()
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
#endif