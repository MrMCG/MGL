#pragma once

#include <vector>

#include "VboBuffer.h"

namespace MGL {

	class VboBufferVec3 : public VboBuffer {
	public:
		VboBufferVec3(std::vector<float> const& data);
		void bufferData(int const location) const;

	private:
		std::vector<float> m_data;
	};

} // MGL