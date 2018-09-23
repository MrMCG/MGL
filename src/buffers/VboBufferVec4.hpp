#pragma once

#include <vector>

#include "Types.hpp"
#include "VboBuffer.hpp"

namespace MGL {

	class VboBufferVec4 : public VboBuffer {
	public:
		VboBufferVec4(std::vector<Vec4> const& data);
		void bufferData(int const location) const override;

	private:
		std::vector<Vec4> const& m_data;
	};

} // MGL
