#pragma once

#include "VboBuffer.h"

namespace MGL {

	class VertexBuffer : public VboBuffer {
	public:
		VertexBuffer(VaoBuffer const& mglVao);

		void bufferData() const override;

	private:
		float vertices[12] = {
			-0.5f,  0.5f, 0.0f,  // top left 
			 0.5f,  0.5f, 0.0f,  // top right
			-0.5f, -0.5f, 0.0f,  // bottom left
			 0.5f, -0.5f, 0.0f   // bottom right	
		};
	};

} // MGL