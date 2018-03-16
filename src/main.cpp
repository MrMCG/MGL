#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>

int main(char*, char**) {
			
	glewInit();
	std::cout << "Hello World!" << std::endl;
	std::cin.get();
	return 0;

}