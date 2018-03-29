#include "Renderer.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <exception>
#include <iostream>

#include "Scene.h"
#include "Logger.h"

namespace {

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

	Renderer::Renderer(std::unique_ptr<Window> window) : m_window(std::move(window)){
		LOGD("GLEW init");
		if (glewInit() != GLEW_OK) {
			throw std::runtime_error("Failed to init GLEW!");
		}

		if (ENABLE_DEBUG) {
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			glDebugMessageCallback((GLDEBUGPROC)MessageCallback, 0); // should check if this exists in context first
			LOGD("Debug Context enabled");
		}
	}

	void Renderer::run() const {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // some default values
		glViewport(0, 0, 800, 600);

		while (!m_window->shouldClose())
		{
			glClear(GL_COLOR_BUFFER_BIT);
		
			if (m_scene)
				m_scene->draw();

			m_window->swapBuffers();
			glfwPollEvents();
		}
	}

	void Renderer::attachScene(std::shared_ptr<Scene> scene) {
		LOGD("Attaching new scene");
		m_scene = scene;
	}

} // MGL