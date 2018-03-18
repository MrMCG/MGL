#pragma once
#include <string>

struct GLFWwindow;

class MGLContextManager {
public:
	MGLContextManager();
	~MGLContextManager();

	void init();
	void init(int width, int height, std::string const& winTitle);

	void run();

	MGLContextManager(MGLContextManager && rhs); // move constructor
	MGLContextManager & operator=(MGLContextManager && rhs); // move assignment

	MGLContextManager(MGLContextManager const& rhs) = delete; // NO copy constructor
	MGLContextManager & operator=(MGLContextManager const& rhs) = delete; // NO copy assignment

private:
	GLFWwindow * m_window = nullptr;

	void cleanup();
	void setWindowHints();
};