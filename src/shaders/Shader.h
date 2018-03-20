#pragma once

#include <string>

#include "ShaderType.h"

#include <iostream>

namespace MGL {

	class Shader {
	public:

		Shader(ShaderType shaderType);
		Shader(std::string const& shaderSrc, ShaderType shaderType);
		~Shader();

		int getShaderVal() const { return m_shaderVal; }
		ShaderType getShaderType() const { return m_shaderType; }

	private:
		int m_shaderVal = -1;
		ShaderType m_shaderType;

		void compile();
		static std::string const determineShdaerDefault(ShaderType shaderType);
	};

} // MGL