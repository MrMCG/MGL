#include "Scene.h"

#include "Shader.h"
#include "ShaderProgram.h"
#include "VaoBuffer.h"
#include "VertexBuffer.h"

#include <GL/glew.h>

namespace MGL {

	Scene::Scene() {

	}

	Scene::~Scene() {

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

		m_vertex->bufferData();
	}

	void Scene::draw() {

		m_program->use();
		m_vao->bind();
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	}

}