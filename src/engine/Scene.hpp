#pragma once

#include <memory>

namespace MGL {

	class ShaderProgram;
	class GraphicsObject;
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
		GraphicsObject* m_square;

		std::shared_ptr<Input> m_input;
	};
} // MGL