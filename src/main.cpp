#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(char*, char**) {
			
	glewInit();
	glfwInit();
	std::cout << "Hello World!" << std::endl;
	std::cin.get();
	return 0;

}