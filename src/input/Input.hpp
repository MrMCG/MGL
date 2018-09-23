#pragma once

#include <unordered_map>

namespace MGL {

	class Input {
	public:

		bool isPressed(char key);
		
		void clear();
		void addSate(char key, int state);

	private:
		std::unordered_map<char, int> m_keyStates{};
	};

} // MGL