#include "GraphicsObject.h"

namespace MGL {
	
	GraphicsObject::GraphicsObject(std::unique_ptr<Mesh> mesh, ShaderProgram const& shaderProgram) : m_mesh(std::move(mesh)), m_shaderProgram(shaderProgram) {
	}

	void GraphicsObject::build() {
		m_shaderProgram.link();
		m_mesh->bufferData();
	}

	void GraphicsObject::draw() const {
		m_shaderProgram.use();
		m_mesh->draw();
	}

} // MGL