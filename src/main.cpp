#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>

#include "MGLContextManager.h"

int main(char*, char**) {
	
	MGLContextManager rendererContext{};

	try {
		rendererContext.init();
	}
	catch (std::exception const& e) {
		std::cout << "Failed to init window manager! : " << e.what() << std::endl;
		return -1;
	}

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glViewport(0, 0, 800, 600);

	rendererContext.run();

	return 0;
}