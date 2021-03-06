#include "GL/glew.h"

#include "VaoBuffer.hpp"
#include "Logger.hpp"

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

	void VaoBuffer::setBuffer(int location, std::unique_ptr<VboBuffer> buffer) {
		if (m_buffers.find(location) != m_buffers.end()) {
			LOGD("overriding buffer at location (" << location << ") which already exists!");
		}

		m_buffers.emplace(location, std::move(buffer));
	}

	void VaoBuffer::bufferAll() const {
		bind();
		for (auto const& buffer : m_buffers) {
			buffer.second->bufferData(buffer.first);
		}
		// unbind needed ??
	}

} // MGL
