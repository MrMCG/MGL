#include <GLFW\glfw3.h>

#include "Input.h"
#include "Logger.h"

namespace MGL {

	bool Input::isPressed(char key) {
		if (m_keyStates.find(key) != m_keyStates.end()) {
			return m_keyStates.at(key) == GLFW_PRESS;
		}

		return false;
	}

	void Input::clear() {
		m_keyStates.clear();
	}

	void Input::addSate(char key, int state) {
		m_keyStates[key] = state;
	}

} // MGL