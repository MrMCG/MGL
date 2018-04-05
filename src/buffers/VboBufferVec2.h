#pragma once

#include <vector>

#include "Types.h"
#include "VboBuffer.h"

namespace MGL {

	class VboBufferVec2 : public VboBuffer {
	public:
		VboBufferVec2(std::vector<Vec2> const& data);
		void bufferData(int const location) const override;

	private:
		std::vector<Vec2> const& m_data;
	};

} // MGL