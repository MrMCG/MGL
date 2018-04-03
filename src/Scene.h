#pragma once

#include <memory>

namespace MGL {

	class VaoBuffer;
	class ShaderProgram;
	class Input;

	class Scene {
	public:
		Scene();
		~Scene();

		void load();
		void draw();

		void update();

		void setInput(std::shared_ptr<Input> input);

	private:
		ShaderProgram * m_program;
		VaoBuffer* m_vao;

		std::shared_ptr<Input> m_input;
	};
} // MGL