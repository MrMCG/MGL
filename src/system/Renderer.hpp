#pragma once

#include <memory>

#include "Window.hpp"
#include "Scene.hpp"

namespace MGL {

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
