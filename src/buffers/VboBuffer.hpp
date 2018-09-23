#pragma once

namespace MGL {

	class VboBuffer {
	public:
		VboBuffer();
		virtual ~VboBuffer();
		virtual void bufferData(int const location) const = 0;

	protected:
		void bind() const;
		static void unbind();

	private:
		unsigned int m_vbo = 0;
	
	};

} // MGL