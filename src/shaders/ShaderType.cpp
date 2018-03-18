#include "ShaderType.h"

#include <GL/glew.h>

#include <exception>
#include <string>

namespace {
	auto constexpr MGL_VERTEX_SHADER_VAL   = GL_VERTEX_SHADER;
	auto constexpr MGL_FRAGMENT_SHADER_VAL = GL_FRAGMENT_SHADER;

	auto constexpr MGL_VERTEX_SHADER_STR = "VERTEX";
	auto constexpr MGL_FRAGMENT_SHADER_STR = "FRAGMENT";
}

unsigned int to_uint(ShaderType shaderType) {
	switch (shaderType) {
	case ShaderType::Vertex:
		return MGL_VERTEX_SHADER_VAL;
		break;
	case ShaderType::Fragment:
		return MGL_FRAGMENT_SHADER_VAL;
		break;
	default:
		throw std::exception("Invalid ShaderType given!");
		break;
	}
}

std::ostream & operator<<(std::ostream & os, ShaderType shaderType) {
	switch (shaderType) {
	case ShaderType::Vertex:
		os << MGL_VERTEX_SHADER_STR;
		break;
	case ShaderType::Fragment:
		os << MGL_FRAGMENT_SHADER_STR;
		break;
	default:
		os << "INVALID";
		break;
	}

	return os;
}