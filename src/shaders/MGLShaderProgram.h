#pragma once

#include "MGLShader.h"

class MGLShaderProgram {
public:
	MGLShaderProgram();

	void attach(MGLShader const& mglShader);
	void link();

private:
	int m_program = -1;
};