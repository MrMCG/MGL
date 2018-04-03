#pragma once

#include <unordered_map>
#include <memory>

#include "VboBuffer.h"

namespace MGL {

	class VaoBuffer {
	public:
		VaoBuffer();
		~VaoBuffer();

		void addBuffer(int location, std::unique_ptr<VboBuffer> buffer);
		void bufferAll() const;

		void bind() const;
		static void unbind();

	private:
		unsigned int m_vao = 0;
		std::unordered_map<int, std::unique_ptr<VboBuffer>> m_buffers{};
	};

} // MGL