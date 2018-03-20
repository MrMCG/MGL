#include "VaoBuffer.h"
#include <GL/glew.h>

namespace MGL {

	VaoBuffer::VaoBuffer() {
		glGenVertexArrays(1, &m_vao);
	}

	VaoBuffer::~VaoBuffer() {
		glDeleteVertexArrays(1, &m_vao);
	}

	void VaoBuffer::bind() const {
		glBindVertexArray(m_vao);
	}

	void VaoBuffer::unbind() const {
		glBindVertexArray(0);
	}

} // MGL