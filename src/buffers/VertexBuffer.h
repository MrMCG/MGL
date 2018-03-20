#pragma once

#include "VboBuffer.h"

#include <vector>

namespace MGL {

	class VertexBuffer : public VboBuffer {
	public:
		VertexBuffer(VaoBuffer const& mglVao);
		VertexBuffer(VaoBuffer const& mglVao, std::vector<float> const& vertices);

		void bufferData() const override;

	private:
		std::vector<float> m_vertices;
	};

} // MGL