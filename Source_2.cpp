#define GLFW_INCLUDE_NONE
//  API for creating windows, contexts and surfaces, receiving input and events.
#include<GLFW/glfw3.h> 
// extension loader library -- provides efficient run-time mechanisms for determining which OpenGL extensions are supported on the target platform.
// most of the time "ELL" needs to be mentioned before GLFW or window, context lib
#include<GL/glew.h> 
// c++ default libs
#include<iostream>
using namespace std;

// 2 functions
void init(GLFWwindow* window){
}

void display(GLFWwindow* window, double currentTime) {
	// RGBA
	glClearColor(1.0, 0.5, 0.27, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

// Expected a declaration error -- https://mrcodehunter.com/c-expected-a-declaration/#:~:text=When%20any%20function%20or%20statement%20is%20not%20in,then%20make%20mistake%20in%20c%2B%2B%20code%20for%20namespace.
int main() {
	if (!glfwInit()) {
		// Initialization failed
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	glfwMakeContextCurrent(window);
	// Initialize Glew
	if (glewInit() != GLEW_OK) {
		exit(EXIT_FAILURE);
	}
	// vsync
	glfwSwapInterval(1);
	
	//init(window);
	while (!glfwWindowShouldClose(window)) {
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	glfwDestroyWindow(window);
}