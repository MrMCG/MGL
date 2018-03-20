#pragma once

#include "VboBuffer.h"

#include <vector>

namespace MGL {

	class ColourBuffer : public VboBuffer {
	public:
		ColourBuffer(VaoBuffer const& mglVao);
		ColourBuffer(VaoBuffer const& mglVao, std::vector<float> const& colours);

		void bufferData() const override;

	private:
		std::vector<float> m_colours;
	};

} // MGL
