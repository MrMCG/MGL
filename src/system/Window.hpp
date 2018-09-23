#pragma once

#include <string>
#include <memory>

#include "Input.hpp"

struct GLFWwindow;
struct GLFWmonitor;

namespace MGL {

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
		void pollEvents() const;

		void updateInput(char key, int state);

		std::shared_ptr<Input> getInput() { return m_input; };

	private:
		GLFWwindow *  m_window  = nullptr;
		GLFWmonitor * m_monitor = nullptr;

		std::shared_ptr<Input> m_input = std::make_shared<Input>();

		void setWindowHints();
	};

} // MGL#pragma once
