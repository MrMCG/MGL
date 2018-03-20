#pragma once

#include "Shader.h"

namespace MGL {

	class ShaderProgram {
	public:
		ShaderProgram();

		void attach(Shader const& mglShader);
		void link();
		void use();

	private:
		int m_program = -1;
	};

} // MGL