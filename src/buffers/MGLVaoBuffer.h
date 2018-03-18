#pragma once

class MGLVaoBuffer {
public:

	MGLVaoBuffer();
	~MGLVaoBuffer();

	void bind() const;
	void unbind() const;

private:
	unsigned int m_vao = 0;
};