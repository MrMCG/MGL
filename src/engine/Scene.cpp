#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Scene.hpp"
#include "Shader.hpp"
#include "ShaderProgram.hpp"
#include "Logger.hpp"
#include "Input.hpp"
#include "FileSystem.hpp"
#include "Mesh.hpp"
#include "GraphicsObject.hpp"

#include <cmath>

namespace MGL {

	Scene::Scene() {

	}

	Scene::~Scene() {
		delete m_program;
		delete m_square;
	}

	void Scene::setInput(std::shared_ptr<Input> input) {
		m_input = input;
	}

	void Scene::load() {

		// load shaders from file
		Shader vert(GetFileAsString("vertShader.txt"), ShaderType::Vertex );
		Shader fragment(GetFileAsString("fragShader.txt"), ShaderType::Fragment);

		// set vertex colours
		auto cols = std::vector<Vec4>{
			{ 0.7f, 0.2f, 0.2f, 1.0f },
			{ 0.2f, 0.7f, 0.2f, 1.0f },
			{ 0.2f, 0.2f, 0.7f, 1.0f },
		};

		// set vertex positions
		auto verts = std::vector<Vec3>{
			{-0.5f, -0.5f, 0.0f},
			{0.5f, -0.5f, 0.0f},
			{0.0f,  0.5f, 0.0f}
		};

		auto colPtr = std::make_unique<std::vector<Vec4>>(cols);
		auto vertPtr = std::make_unique<std::vector<Vec3>>(verts);

		// create new shader program
		m_program = new ShaderProgram();

		// attach shaders
		m_program->attach(vert);
		m_program->attach(fragment);
	
		// setup mesh
		auto mesh = std::make_unique<Mesh>(std::move(vertPtr));
		mesh->setColours(std::move(colPtr));

		// create graphics object
		m_square = new GraphicsObject(std::move(mesh), *m_program);

		// 'build' (setup opengl)
		m_square->build();
	}

	void Scene::update() {
		if (m_input->isPressed('S')) {
			LOGI("hello from scene!");
		}

		float val = (std::sin(glfwGetTime()) + 1) / 2.0f;
		m_program->setUniform( "col", val);
	}

	void Scene::draw() {
		m_square->draw();
	}

}
