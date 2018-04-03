#pragma once

#include <memory>

#include "Window.h"

namespace MGL {

	class Scene;

	class Renderer {
	public:
		Renderer(std::unique_ptr<Window> window);

		void run() const;

		void attachScene(std::shared_ptr<Scene> scene);

	private:
		std::unique_ptr<Window> m_window;
		std::shared_ptr<Scene> m_scene;
	};

} // MGL