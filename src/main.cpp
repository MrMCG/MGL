#include <iostream>

#include "MGLContextManager.h"
#include "MGLShader.h"
#include "MGLShaderProgram.h"

int main(char*, char**) {
	
	MGLContextManager rendererContext{};

	try {
		rendererContext.init();
	}
	catch (std::exception const& e) {
		std::cout << "Failed to init window manager! : " << e.what() << std::endl;
		return -1;
	}

	MGLShader vert(ShaderType::Vertex);
	MGLShader fragment(ShaderType::Fragment);

	MGLShaderProgram program;

	program.attach(vert);
	program.attach(fragment);
	program.link();

	


	rendererContext.run();

	return 0;
}