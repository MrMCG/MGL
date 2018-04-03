#include <GL\glew.h>

#include "VaoBuffer.h"
#include "Logger.h"

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

	void VaoBuffer::unbind() {
		glBindVertexArray(0);
	}

	void VaoBuffer::addBuffer(int location, std::unique_ptr<VboBuffer> buffer) {
		if (m_buffers.find(location) != m_buffers.end()) {
			LOGE("overriding buffer at location (" << location << ") which already exists!");
		}

		m_buffers.emplace(location, std::move(buffer));
	}

	void VaoBuffer::bufferAll() const {
		bind();
		for (auto const& buffer : m_buffers) {
			buffer.second->bufferData(buffer.first);
		}
	}

} // MGL