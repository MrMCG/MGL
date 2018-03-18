#pragma once

#include "MGLVaoBuffer.h"

class MGLVboBuffer {
public:

	MGLVboBuffer(MGLVaoBuffer const& mglVao);
	virtual ~MGLVboBuffer();

	virtual void bufferData() const = 0;

protected:
	unsigned int m_vbo = 0;
	MGLVaoBuffer m_mglVao;
};