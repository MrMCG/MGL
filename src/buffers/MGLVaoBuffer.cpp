#include "MGLVaoBuffer.h"
#include <GL/glew.h>

MGLVaoBuffer::MGLVaoBuffer() {
	glGenVertexArrays(1, &m_vao);
}

MGLVaoBuffer::~MGLVaoBuffer() {
	glDeleteVertexArrays(1, &m_vao);
}

void MGLVaoBuffer::bind() const {
	glBindVertexArray(m_vao);
}

void MGLVaoBuffer::unbind() const {
	glBindVertexArray(0);
}