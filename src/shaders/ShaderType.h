#pragma once
#include <iosfwd>

enum class ShaderType {
	Vertex,
	Fragment
};

unsigned int to_uint(ShaderType shaderType);
std::ostream & operator<<(std::ostream &, ShaderType shaderType);