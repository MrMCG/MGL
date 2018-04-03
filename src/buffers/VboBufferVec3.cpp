#include <GL\glew.h>

#include "VboBufferVec3.h"

namespace MGL {

	VboBufferVec3::VboBufferVec3(std::vector<float> const& data) : m_data(data) {}

	void VboBufferVec3::bufferData(int const location) const {
		bind();
		glBufferData(GL_ARRAY_BUFFER, m_data.size() * sizeof(float), &m_data.at(0), GL_STATIC_DRAW);
		glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
		glEnableVertexAttribArray(location);

		// unbind(); // needed?

	}

}