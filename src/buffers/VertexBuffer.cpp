#include "VertexBuffer.h"
#include <GL/glew.h>

namespace MGL {

	VertexBuffer::VertexBuffer(VaoBuffer const& mglVao) : VboBuffer(mglVao) {}

	void VertexBuffer::bufferData() const {
		m_mglVao.bind();
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		m_mglVao.unbind();
	}

} // MGL