#include "MGLShaderProgram.h"

#include <GL/glew.h>

#include <iostream>

namespace {

	auto constexpr INFO_LOG_SIZE = 512;

}

MGLShaderProgram::MGLShaderProgram() {
	m_program = glCreateProgram();
}

void MGLShaderProgram::link() {
	glLinkProgram(m_program);

	auto success = -1;
	char infoLog[INFO_LOG_SIZE];

	glGetProgramiv(m_program, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(m_program, INFO_LOG_SIZE, nullptr, infoLog);
		std::cout << "Error: program linking failed: " << infoLog << std::endl;
	}
}

void MGLShaderProgram::attach(MGLShader const& mglShader) {
	glAttachShader( m_program, mglShader.getShaderVal() );
}

