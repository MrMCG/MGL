#pragma once

#include "MGLVboBuffer.h"

class MGLVertexBuffer : public MGLVboBuffer {
public:
	MGLVertexBuffer(MGLVaoBuffer const& mglVao);

	void bufferData() const override;

private:
	float vertices[12] = {
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};
};