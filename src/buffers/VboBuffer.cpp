#include <GL/glew.h>

#include "VboBuffer.hpp"

namespace MGL {

	VboBuffer::VboBuffer() {
		glGenBuffers(1, &m_vbo);
	}

	VboBuffer::~VboBuffer() {
		glDeleteBuffers(1, &m_vbo);
	}

	void VboBuffer::bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	}

	void VboBuffer::unbind() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

} // MGL
