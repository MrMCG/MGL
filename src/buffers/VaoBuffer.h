#pragma once

namespace MGL {

	class VaoBuffer {
	public:

		VaoBuffer();
		~VaoBuffer();

		void bind() const;
		void unbind() const;

	private:
		unsigned int m_vao = 0;
	};

} // MGL