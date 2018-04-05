#pragma once

#include <vector>
#include <memory>

#include "Types.h"
#include "VaoBuffer.h"

namespace MGL {

	class Mesh {
	public:
		Mesh(std::unique_ptr<std::vector<Vec3>> positions);

		void setColours(std::unique_ptr<std::vector<Vec4>> colours);

		void bufferData() const;
		void draw() const;

	private:
		std::unique_ptr<std::vector<Vec3>> m_positions = nullptr;
		std::unique_ptr<std::vector<Vec4>> m_colours = nullptr;

		VaoBuffer m_vao{};
	};

} // MGL