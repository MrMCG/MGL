#include "Window.h"

#include <GLFW/glfw3.h>

#include <exception>
#include <iostream>

#include "Logger.h"

namespace {
	auto constexpr MAJOR_VERSION = 4;
	auto constexpr MINOR_VERSION = 4;

	auto constexpr DEFAULT_WIDTH = 800;
	auto constexpr DEFAULT_HEIGHT = 600;
	auto constexpr DEFAULT_REFRESH = 60;
	auto constexpr DEFAULT_XPOS = 40;
	auto constexpr DEFAULT_YPOS = 40;

	auto constexpr DEFAULT_WIN_TITLE = "Default Window";

#ifdef _DEBUG
	auto constexpr ENABLE_DEBUG{ true };
#else
	auto constexpr ENABLE_DEBUG{ false };
#endif

}

namespace MGL {

	Window::Window() : Window(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_WIN_TITLE) {}

	Window::Window(int width, int height, std::string const& winTitle) {
		LOGD("GLFW init");
		if (glfwInit() != GLFW_TRUE) {
			throw std::runtime_error("Failed to init GLFW!");
		}

		setWindowHints();

		LOGD("creating window: " << width << "x" << height << " " << winTitle);
		m_window = glfwCreateWindow(800, 600, winTitle.c_str(), nullptr, nullptr);

		if (m_window == nullptr) {
			throw std::runtime_error("Failed to create glfwWindow!");
		}

		m_monitor = glfwGetPrimaryMonitor();
			
		glfwMakeContextCurrent(m_window);
	}

	Window::~Window() {
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void Window::setWindowed(int width, int height, int refreshRate) const {
		LOGD("Setting windowed");
		glfwSetWindowMonitor(m_window, nullptr, DEFAULT_XPOS, DEFAULT_YPOS, width, height, refreshRate);
		glViewport(0, 0, width, height);
	}

	void Window::setFullscreen(int width, int height, int refreshRate) const {
		LOGD("Setting fullscreen");
		glfwSetWindowMonitor(m_window, m_monitor, 0, 0, width, height, refreshRate);
		glViewport(0, 0, width, height);
	}

	void Window::setBorderlessFullscreen() const {
		LOGD("Setting borderless fullscreen");
		GLFWvidmode const* mode = glfwGetVideoMode(m_monitor);
		glfwSetWindowMonitor(m_window, nullptr, 0, 0, mode->width, mode->height, mode->refreshRate);
		glViewport(0, 0, mode->width, mode->height);
		std::cout << mode->width << '\n';
		std::cout << mode->height << '\n';
		std::cout << mode->refreshRate << std::endl;
	}

	bool Window::shouldClose() const {
		return glfwWindowShouldClose(m_window);
	}



	void Window::swapBuffers() const {

		static auto state1 = false;
		static auto state2 = false;
		static auto state3 = false;

		if (glfwGetKey(m_window, GLFW_KEY_K) == GLFW_PRESS) {
			if (state1 == false) {
				std::cout << "bigger" << std::endl;
				setWindowed(600, 400, 60);
			}
			state1 = true;		
		}
		else {
			state1 = false;
		}

		if (glfwGetKey(m_window, GLFW_KEY_L) == GLFW_PRESS) {
			if (state2 == false) {
				std::cout << "smaller" << std::endl;
				setFullscreen(1000, 800, 60);
			}
			state2 = true;
		}
		else {
			state2 = false;
		}

		if (glfwGetKey(m_window, GLFW_KEY_J) == GLFW_PRESS) {
			if (state3 == false) {
				std::cout << "smaller" << std::endl;
				setBorderlessFullscreen();
			}
			state3 = true;
		}
		else {
			state3 = false;
		}


		glfwSwapBuffers(m_window);
	}

	void Window::setWindowHints() {
		LOGD("Setting window hints");
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, MAJOR_VERSION);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, MINOR_VERSION);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_REFRESH_RATE, DEFAULT_REFRESH);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		if (ENABLE_DEBUG) {
			LOGD("Setting openGL debug context");
			glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
		}
	}

} // MGL