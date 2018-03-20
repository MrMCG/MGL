#include <iostream>

#include <GL/glew.h>

#include "ContextManager.h"
#include "Scene.h"

int main(char*, char**) {
	
	MGL::ContextManager rendererContext{};

	try {
		rendererContext.init();
	}
	catch (std::exception const& e) {
		std::cout << "Failed to init window manager! : " << e.what() << std::endl;
		return -1;
	}

	auto scene = std::make_shared<MGL::Scene>();
	scene->load();

	rendererContext.attaachScene(scene);

	rendererContext.run();

	return 0;
}