#include "Shader.h"

#include <GL/glew.h>

#include <iostream>

namespace {

	auto constexpr INFO_LOG_SIZE = 512;

	auto constexpr DEFAULT_VERTEX_SHADER_SRC =
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}";
	auto constexpr DEFAULT_FRAGMENT_SHADER_SRC =
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n";

#ifdef _DEBUG
	auto constexpr ENABLE_DEBUG{ true };
#else
	auto constexpr ENABLE_DEBUG{ false };
#endif
}

namespace MGL {

	Shader::Shader(ShaderType shaderType) : Shader(determineShdaerDefault(shaderType), shaderType) {
		std::cout << "Loading default shader: " << shaderType << std::endl;
	}

	Shader::Shader(std::string const& shaderSrc, ShaderType shaderType) : m_shaderType(shaderType) {
		m_shaderVal = glCreateShader(to_uint(shaderType));
		auto c_str = shaderSrc.c_str();
		glShaderSource(m_shaderVal, 1, &c_str, nullptr);
		compile();
	}

	Shader::~Shader() {
		glDeleteShader(m_shaderVal);
	}

	void Shader::compile() {
		glCompileShader(m_shaderVal);

		auto success{ -1 };
		char infoLog[INFO_LOG_SIZE];

		glGetShaderiv(m_shaderVal, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(m_shaderVal, INFO_LOG_SIZE, nullptr, infoLog);
			std::cout << "Error: shader compilation failed: " << infoLog << std::endl;
		}

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