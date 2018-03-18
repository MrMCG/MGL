#pragma once

#include <string>

#include "ShaderType.h"

#include <iostream>

class MGLShader {
public:

	MGLShader(ShaderType shaderType);
	MGLShader(std::string const& shaderSrc, ShaderType shaderType);
	~MGLShader();

	int getShaderVal() const { return m_shaderVal;  }
	ShaderType getShaderType() const { return m_shaderType; }

private:
	int m_shaderVal = -1;
	ShaderType m_shaderType;

	void compile();
	static std::string const determineShdaerDefault(ShaderType shaderType);
};