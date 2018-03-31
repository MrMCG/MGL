#include <GL/glew.h>
#include <exception>
#include <string>

#include "ShaderType.h"

namespace {
	auto constexpr VERTEX_SHADER_VAL   = GL_VERTEX_SHADER;
	auto constexpr FRAGMENT_SHADER_VAL = GL_FRAGMENT_SHADER;

	auto constexpr VERTEX_SHADER_STR = "VERTEX";
	auto constexpr FRAGMENT_SHADER_STR = "FRAGMENT";
}

namespace MGL {

	unsigned int to_uint(ShaderType shaderType) {
		switch (shaderType) {
		case ShaderType::Vertex:
			return VERTEX_SHADER_VAL;
			break;
		case ShaderType::Fragment:
			return FRAGMENT_SHADER_VAL;
			break;
		default:
			throw std::exception("Invalid ShaderType given!");
			break;
		}
	}

	std::ostream & operator<<(std::ostream & os, ShaderType shaderType) {
		switch (shaderType) {
		case ShaderType::Vertex:
			os << VERTEX_SHADER_STR;
			break;
		case ShaderType::Fragment:
			os << FRAGMENT_SHADER_STR;
			break;
		default:
			os << "INVALID";
			break;
		}

		return os;
	}

} // MGL