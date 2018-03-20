#pragma once

#include "VaoBuffer.h"

namespace MGL {

	class VboBuffer {
	public:

		VboBuffer(VaoBuffer const& mglVao);
		virtual ~VboBuffer();

		virtual void bufferData() const = 0;

	protected:
		unsigned int m_vbo = 0;
		VaoBuffer m_mglVao;
	};

} // MGL