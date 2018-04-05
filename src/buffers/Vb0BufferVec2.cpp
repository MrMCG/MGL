#include <GL\glew.h>

#include "VboBufferVec2.h"

namespace MGL {

	VboBufferVec2::VboBufferVec2(std::vector<Vec2> const& data) : m_data(data) {}

	void VboBufferVec2::bufferData(int const location) const {
		bind();
		glBufferData(GL_ARRAY_BUFFER, m_data.size() * sizeof(Vec2), &m_data.at(0), GL_STATIC_DRAW);
		glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
		glEnableVertexAttribArray(location);

		// unbind(); // needed?

	}

} // MGL