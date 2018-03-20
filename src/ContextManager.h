#pragma once

#include <string>
#include <memory>

struct GLFWwindow;

namespace MGL {

	class Scene;

	class ContextManager {
	public:
		ContextManager();
		~ContextManager();

		void init();
		void init(int width, int height, std::string const& winTitle);

		void run();

		void attaachScene(std::shared_ptr<Scene> scene);

		ContextManager(ContextManager && rhs); // move constructor
		ContextManager & operator=(ContextManager && rhs); // move assignment

		ContextManager(ContextManager const& rhs) = delete; // NO copy constructor
		ContextManager & operator=(ContextManager const& rhs) = delete; // NO copy assignment

	private:
		GLFWwindow * m_window = nullptr;
		std::shared_ptr<Scene> m_scene;

		void cleanup();
		void setWindowHints();
	};

} // MGL