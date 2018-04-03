#include <GL/glew.h>
#include <GLFW\glfw3.h>

#include "Scene.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "VaoBuffer.h"
#include "VboBufferVec3.h"
#include "Logger.h"
#include "Input.h"
#include "FileSystem.h"

#include <cmath>
#include <chrono>

namespace MGL {

	Scene::Scene() {

	}

	Scene::~Scene() {
		delete m_program;
		delete m_vao;
	}

	void Scene::setInput(std::shared_ptr<Input> input) {
		m_input = input;
	}

	void Scene::load() {

		Shader vert(GetFileAsString("vertShader.txt"), ShaderType::Vertex );
		Shader fragment(GetFileAsString("fragShader.txt"), ShaderType::Fragment);

		m_program = new ShaderProgram();

		m_program->attach(vert);
		m_program->attach(fragment);
		m_program->link();

		auto m_colours = std::vector<float>{
			0.7f, 0.2f, 0.2f,
			0.2f, 0.7f, 0.2f,
			0.2f, 0.2f, 0.7f,
			0.2f, 0.2f, 0.2f
		};

		auto m_vertices = std::vector<float>{
			-0.5f,  0.5f, 0.0f,  // top left 
			0.5f,  0.5f, 0.0f,  // top right
			-0.5f, -0.5f, 0.0f,  // bottom left
			0.5f, -0.5f, 0.0f   // bottom right	
		};

		m_vao = new VaoBuffer();
		m_vao->addBuffer(0, std::make_unique<VboBufferVec3>(m_vertices));
		m_vao->addBuffer(1, std::make_unique<VboBufferVec3>(m_colours));

		m_vao->bufferAll();
	}

	void Scene::update() {
		if (m_input->isPressed('S')) {
			LOGI("hello from scene!");
		}

		float val = (std::sin(glfwGetTime()) + 1) / 2.0f;
		m_program->setUniform( "col", val);
	}

	void Scene::draw() {
		m_program->use();
		m_vao->bind();
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	}

}