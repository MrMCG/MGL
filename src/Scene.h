#pragma once

namespace MGL {

	class VaoBuffer;
	class VertexBuffer;
	class ColourBuffer;
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
		ColourBuffer* m_colour;

		bool m_loaded = false;
	};
} // MGL