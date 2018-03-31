#include <GL/glew.h>

#include "Scene.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "VaoBuffer.h"
#include "VertexBuffer.h"
#include "ColourBuffer.h"
#include "Logger.h"
#include "Input.h"

namespace MGL {

	Scene::Scene() {

	}

	Scene::~Scene() {

	}

	void Scene::setInput(std::shared_ptr<Input> input) {
		m_input = input;
	}

	void Scene::load() {
		Shader vert(ShaderType::Vertex);
		Shader fragment(ShaderType::Fragment);

		m_program = new ShaderProgram();

		m_program->attach(vert);
		m_program->attach(fragment);
		m_program->link();

		m_vao = new VaoBuffer();
		m_vertex = new VertexBuffer{ *m_vao };
		m_colour = new ColourBuffer{ *m_vao };

		m_vertex->bufferData();
		m_colour->bufferData();

	}

	void Scene::update() {
		if (m_input->isPressed('S')) {
			LOGI("hello from scene!");
		}
	}

	void Scene::draw() {
		m_program->use();
		m_vao->bind();
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	}

}