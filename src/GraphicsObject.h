#pragma once

#include <deque>
#include <memory>

#include "Mesh.h"
#include "ShaderProgram.h"

namespace MGL {

	class GraphicsObject {
	public:
		GraphicsObject(std::unique_ptr<Mesh> mesh, ShaderProgram const& shaderProgram);

		void setShader(ShaderProgram shaderProgram) {};

		void build();
		void draw() const;

	private:
		std::unique_ptr<Mesh> m_mesh;
		ShaderProgram m_shaderProgram;
	};

} // MGL