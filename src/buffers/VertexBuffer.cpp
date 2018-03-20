#include "VertexBuffer.h"
#include <GL/glew.h>

namespace MGL {

	VertexBuffer::VertexBuffer(VaoBuffer const& mglVao) : VboBuffer(mglVao) {
		m_vertices = std::vector<float>  {
			-0.5f,  0.5f, 0.0f,  // top left 
			 0.5f,  0.5f, 0.0f,  // top right
			-0.5f, -0.5f, 0.0f,  // bottom left
			 0.5f, -0.5f, 0.0f   // bottom right	
		};
	}

	VertexBuffer::VertexBuffer(VaoBuffer const& mglVao, std::vector<float> const& vertices) : VboBuffer(mglVao), m_vertices(vertices) {}

	void VertexBuffer::bufferData() const {
		m_mglVao.bind();
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

		glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), &m_vertices.at(0), GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		m_mglVao.unbind();
	}

} // MGL