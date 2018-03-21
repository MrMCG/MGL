#include <string>


struct GLFWwindow;
struct GLFWmonitor;

namespace MGL {

	class Scene;

	class Window {
	public:
		Window();
		Window(int width, int height, std::string const& winTitle);
		~Window();

		void setWindowed(int width, int height, int refreshrate = 60) const;
		void setFullscreen(int width, int height, int refreshrate = 60) const;
		void setBorderlessFullscreen() const;

		bool shouldClose() const;
		void swapBuffers() const;

	private:
		GLFWwindow *  m_window  = nullptr;
		GLFWmonitor * m_monitor = nullptr;

		void setWindowHints();
	};

} // MGL#pragma once
