#include <GL/glew.h>

#include "VboBufferVec4.hpp"

namespace MGL {

	VboBufferVec4::VboBufferVec4(std::vector<Vec4> const& data) : m_data(data) {}

	void VboBufferVec4::bufferData(int const location) const {
		bind();
		glBufferData(GL_ARRAY_BUFFER, m_data.size() * sizeof(Vec4), &m_data.at(0), GL_STATIC_DRAW);
		glVertexAttribPointer(location, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
		glEnableVertexAttribArray(location);

		// unbind(); // needed?

	}

} // MGL
