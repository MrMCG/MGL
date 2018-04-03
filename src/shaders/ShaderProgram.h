#pragma once

#include <string>

namespace MGL {

	class Shader;

	class ShaderProgram {
	public:
		ShaderProgram();

		void attach(Shader const& mglShader) const;
		void link() const;
		void use() const;

		void setUniform(std::string name, float val) const;
		void setUniform(std::string name, int val) const;

	private:
		int m_program = -1;

		int getUniformLocation(std::string name) const;
	};

} // MGL