#include <GL/glew.h>

#include "ColourBuffer.h"

namespace MGL {

	ColourBuffer::ColourBuffer(VaoBuffer const& mglVao) : VboBuffer(mglVao) {
		m_colours = std::vector<float>{
			0.7f, 0.2f, 0.2f,
			0.2f, 0.7f, 0.2f,
			0.2f, 0.2f, 0.7f,
			0.2f, 0.2f, 0.2f
		};
	}

	ColourBuffer::ColourBuffer(VaoBuffer const& mglVao, std::vector<float> const& colours) : VboBuffer(mglVao), m_colours(colours) {}

	void ColourBuffer::bufferData() const {
		m_mglVao.bind();
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

		glBufferData(GL_ARRAY_BUFFER, m_colours.size() * sizeof(float), &m_colours.at(0), GL_STATIC_DRAW);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		m_mglVao.unbind();
	}

} // MGL