#include <GL\glew.h>
#include <memory>

#include "Mesh.h"
#include "VboBufferVec3.h"
#include "VboBufferVec4.h"

namespace {
	enum BufferPositions {
		POSITION = 0,
		COLOUR = 1
	};
}

namespace MGL {

	Mesh::Mesh(std::unique_ptr<std::vector<Vec3>> positions) : m_positions(std::move(positions)) {
		m_vao.setBuffer(BufferPositions::POSITION, std::make_unique<VboBufferVec3>(*m_positions));
	}

	void Mesh::bufferData() const {
		m_vao.bufferAll();
	}

	void Mesh::setColours(std::unique_ptr<std::vector<Vec4>> colours) {
		m_colours = std::move(colours);
		m_vao.setBuffer(BufferPositions::COLOUR, std::make_unique<VboBufferVec4>(*m_colours));

	}

	void Mesh::draw() const{
		m_vao.bind();
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	}


} // MGL