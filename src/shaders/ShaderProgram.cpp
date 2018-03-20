#include "ShaderProgram.h"

#include <GL/glew.h>

#include <iostream>

namespace {

	auto constexpr INFO_LOG_SIZE = 512;

}

namespace MGL {

	ShaderProgram::ShaderProgram() {
		m_program = glCreateProgram();
	}

	void ShaderProgram::link() {
		glLinkProgram(m_program);

		auto success = -1;
		char infoLog[INFO_LOG_SIZE];

		glGetProgramiv(m_program, GL_LINK_STATUS, &success);

		if (!success) {
			glGetProgramInfoLog(m_program, INFO_LOG_SIZE, nullptr, infoLog);
			std::cout << "Error: program linking failed: " << infoLog << std::endl;
		}
	}

	void ShaderProgram::attach(Shader const& mglShader) {
		glAttachShader(m_program, mglShader.getShaderVal());
	}

	void ShaderProgram::use() {
		glUseProgram(m_program);
	}

} // MGL