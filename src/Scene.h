#pragma once

namespace MGL {

	class VaoBuffer;
	class VertexBuffer;
	class ShaderProgram;

	class Scene {
	public:
		Scene();
		~Scene();

		void load();
		void draw();

	private:
		ShaderProgram * m_program;
		VaoBuffer* m_vao;
		VertexBuffer* m_vertex;
	};
} // MGL