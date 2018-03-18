#include "MGLVboBuffer.h"
#include <GL/glew.h>

MGLVboBuffer::MGLVboBuffer(MGLVaoBuffer const& mglVao) : m_mglVao(mglVao) {
	glGenBuffers(1, &m_vbo);
}

MGLVboBuffer::~MGLVboBuffer() {
	glDeleteBuffers(1, &m_vbo);
}