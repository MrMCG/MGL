#pragma once

#include <memory>

#include "Window.h"

struct GLFWwindow;

namespace MGL {

	class Scene;

	class ContextManager {
	public:
		ContextManager(std::unique_ptr<Window> window);

		void run();

		void attaachScene(std::shared_ptr<Scene> scene);

	private:
		std::unique_ptr<Window> m_window;
		std::shared_ptr<Scene> m_scene;
	};

} // MGL