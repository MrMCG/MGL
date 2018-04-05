#pragma once

#include <vector>

#include "Types.h"
#include "VboBuffer.h"

namespace MGL {

	class VboBufferVec3 : public VboBuffer {
	public:
		VboBufferVec3(std::vector<Vec3> const& data);
		void bufferData(int const location) const override;

	private:
		std::vector<Vec3> const& m_data;
	};

} // MGL