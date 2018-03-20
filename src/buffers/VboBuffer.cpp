#include "VboBuffer.h"
#include <GL/glew.h>

namespace MGL {

	VboBuffer::VboBuffer(VaoBuffer const& mglVao) : m_mglVao(mglVao) {
		glGenBuffers(1, &m_vbo);
	}

	VboBuffer::~VboBuffer() {
		glDeleteBuffers(1, &m_vbo);
	}

} // MGL