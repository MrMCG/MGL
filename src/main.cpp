#include <iostream>

#include <GL/glew.h>

#include "ContextManager.h"
#include "Scene.h"

int main(char*, char**) {
	
	auto renderer = std::unique_ptr<MGL::ContextManager>();

	try {

		renderer = std::make_unique<MGL::ContextManager>(std::make_unique<MGL::Window>());
	}
	catch (std::exception const& e) {
		std::cout << "Failed to init window manager! : " << e.what() << std::endl;
		return -1;
	}

	auto scene = std::make_shared<MGL::Scene>();
	scene->load();

	renderer->attaachScene(scene);

	renderer->run();

	return 0;
}