#include "ShaderProgram.h"

#include <GL/glew.h>

#include <iostream>

#include "Logger.h"

namespace {

	auto constexpr INFO_LOG_SIZE = 512;

}

namespace MGL {

	ShaderProgram::ShaderProgram() {
		m_program = glCreateProgram();
		LOGD("Creating program : " << m_program);
	}

	void ShaderProgram::link() {
		LOGD("Linking program : " << m_program);
		glLinkProgram(m_program);

		auto success = -1;
		char infoLog[INFO_LOG_SIZE];

		glGetProgramiv(m_program, GL_LINK_STATUS, &success);

		if (!success) {
			glGetProgramInfoLog(m_program, INFO_LOG_SIZE, nullptr, infoLog);
			LOGE("Program linking failed: " << infoLog);
			return;
		}

		LOGD("Link succes : " << m_program);
	}

	void ShaderProgram::attach(Shader const& mglShader) {
		LOGD("Attaching shader : " << mglShader.getShaderVal() << " to program : " << m_program);
		glAttachShader(m_program, mglShader.getShaderVal());
	}

	void ShaderProgram::use() {
		glUseProgram(m_program);
	}

} // MGL