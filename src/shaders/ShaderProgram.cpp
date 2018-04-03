#include <GL/glew.h>
#include <iostream>

#include "ShaderProgram.h"
#include "Logger.h"
#include "Shader.h"

namespace {

	auto constexpr INFO_LOG_SIZE = 512;

}

namespace MGL {

	ShaderProgram::ShaderProgram() {
		m_program = glCreateProgram();
		LOGD("Creating program : " << m_program);
	}

	void ShaderProgram::link() const {
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

	void ShaderProgram::attach(Shader const& mglShader) const {
		LOGD("Attaching shader : " << mglShader.getShaderVal() << " to program : " << m_program);
		glAttachShader(m_program, mglShader.getShaderVal());
	}

	void ShaderProgram::use() const {
		glUseProgram(m_program);
	}

	int ShaderProgram::getUniformLocation(std::string name) const {
		return glGetUniformLocation(m_program, name.c_str());
	}

	void ShaderProgram::setUniform(std::string name, float val) const {
		glProgramUniform1f(m_program, getUniformLocation(name), val);
	}

	void ShaderProgram::setUniform(std::string name, int val) const {
		glProgramUniform1i(m_program, getUniformLocation(name), val);
	}

} // MGL