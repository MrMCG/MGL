#include "ContextManager.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <exception>
#include <iostream>

#include "Scene.h"

namespace {
	auto constexpr MAJOR_VERSION = 4;
	auto constexpr MINOR_VERSION = 4;

	auto constexpr DEFAULT_WIDTH	 = 800;
	auto constexpr DEFAULT_HEIGHT    = 600;
	auto constexpr DEFAULT_WIN_TITLE = "Default MGLWindow";

#ifdef _DEBUG
	auto constexpr ENABLE_DEBUG{ true };
#else
	auto constexpr ENABLE_DEBUG{ false };
#endif

	void APIENTRY MessageCallback(GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar* message,
		const void* userParam)
	{
		fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
			(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
			type, severity, message);
	}
}

namespace MGL {

	ContextManager::ContextManager() {}

	ContextManager::~ContextManager() {
		cleanup();
		glfwTerminate();
	}

	ContextManager::ContextManager(ContextManager && rhs) : m_window(rhs.m_window) {
		rhs.m_window = nullptr;
	}

	void ContextManager::init() {
		init(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_WIN_TITLE);
	}

	void ContextManager::init(int width, int height, std::string const& winTitle) {
		if (m_window != nullptr) {
			std::cout << "Context already initialised!" << std::endl;
			return;
		}

		if (glfwInit() != GLFW_TRUE) {
			throw std::exception("Failed to init GLFW!");
		}

		setWindowHints();

		m_window = glfwCreateWindow(800, 600, winTitle.c_str(), nullptr, nullptr);

		if (m_window == nullptr) {
			throw std::exception("Failed to create glfwWindow!");
		}

		glfwMakeContextCurrent(m_window);

		if (glewInit() != GLEW_OK) {
			throw std::exception("Failed to init GLEW!");
		}

		if (ENABLE_DEBUG) {
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			glDebugMessageCallback((GLDEBUGPROC)MessageCallback, 0); // should check if this exists in context first
			std::cout << "Debug Context enabled" << std::endl;
		}

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // some default values
		glViewport(0, 0, width, height);
	}

	void ContextManager::run() {
		while (!glfwWindowShouldClose(m_window))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			m_scene->draw();

			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}
	}

	void ContextManager::attaachScene(std::shared_ptr<Scene> scene) {
		m_scene = scene;
	}

	ContextManager & ContextManager::operator=(ContextManager && rhs) {
		cleanup();
		m_window = rhs.m_window;
		rhs.m_window = nullptr;
		return *this;
	}

	void ContextManager::cleanup() {
		if (m_window != nullptr) {
			glfwDestroyWindow(m_window);
			m_window = nullptr;
		}
	}

	void ContextManager::setWindowHints() {
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		if (ENABLE_DEBUG) {
			glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
		}
	}

} // MGL