#include <GL/glew.h>
#include <iostream>

#include "Shader.h"
#include "Logger.h"

namespace {

	auto constexpr INFO_LOG_SIZE = 512;

	auto constexpr DEFAULT_VERTEX_SHADER_SRC =
		"#version 330 core\n"
		"layout (location = 0) in vec3 pos;\n"
		"layout (location = 1) in vec4 col;\n"
		"out vec4 colour;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);\n"
		"   colour = col;\n"
		"}";
	auto constexpr DEFAULT_FRAGMENT_SHADER_SRC =
		"#version 330 core\n"
		"in vec4 colour;\n"
		"out vec4 FragColour;\n"
		"uniform float col;\n"
		"void main()\n"
		"{\n"
		"   FragColour = colour;\n"
		"}\n";

}

namespace MGL {

	Shader::Shader(ShaderType shaderType) : Shader(determineShdaerDefault(shaderType), shaderType) {
		LOGI( "Using default shader: " << shaderType );
	}

	Shader::Shader(std::string const& shaderSrc, ShaderType shaderType) : m_shaderType(shaderType) {
		m_shaderVal = glCreateShader(to_uint(shaderType));

		LOGD("Creating shader ( " << m_shaderType << " ) : " << m_shaderVal << " src: \n" << shaderSrc);

		auto c_str = shaderSrc.c_str();
		glShaderSource(m_shaderVal, 1, &c_str, nullptr);
		compile();
	}

	Shader::~Shader() {
		glDeleteShader(m_shaderVal);
	}

	void Shader::compile() {
		LOGD("Compiling ( " << m_shaderType << " ) : " << m_shaderVal);
		glCompileShader(m_shaderVal);

		auto success{ -1 };
		char infoLog[INFO_LOG_SIZE];

		glGetShaderiv(m_shaderVal, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(m_shaderVal, INFO_LOG_SIZE, nullptr, infoLog);
			LOGE( "Shader compilation failed: " << infoLog );
			return;
		}

		LOGD("Compilation success ( " << m_shaderType << " ) : " << m_shaderVal);
	}

	std::string const Shader::determineShdaerDefault(ShaderType shaderType) {
		switch (shaderType) {
		case ShaderType::Vertex:
			return DEFAULT_VERTEX_SHADER_SRC;
		case ShaderType::Fragment:
			return DEFAULT_FRAGMENT_SHADER_SRC;
		default:
			return "INVALID DEFAULT SHDAERTYPE";
		}
	}

} // MGL