#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h>
#include<GL/glew.h>
#include<iostream>
#define numVAOs 1
#include<string>
#include<fstream>
using namespace std;

GLuint renderingProgram;
GLuint vao[numVAOs];

string readShaderSource(const char* filePath) {
	string content;
	ifstream fileStream(filePath, ios::in);
	string line = "";

	while (!fileStream.eof()) {
		getline(fileStream, line);
		content.append(line + "\n");
	}
	fileStream.close();
	return content;
}


GLuint createShaderProgram() {


 /*https://github.com/ssloy/glsltuto/blob/master/shaders/frag_shader.glsl */
	string vertShaderStr = readShaderSource("D:\\All_Projs\\c++_Proj\\Project2\\vertShader.glsl");
	string fragShaderStr = readShaderSource("D:\\All_Projs\\c++_Proj\\Project2\\fragShader.glsl");

	const char* vertShaderSrc = vertShaderStr.c_str();
	const char* fragShaderSrc = fragShaderStr.c_str();


	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vShader, 1, &vertShaderSrc, NULL);
	glShaderSource(fShader, 1, &fragShaderSrc, NULL);

	glCompileShader(vShader);
	glCompileShader(fShader);

	GLuint vfProgram = glCreateProgram();
	glAttachShader(vfProgram, vShader);
	glAttachShader(vfProgram, fShader);
	glAttachShader(vfProgram, fShader);
	glLinkProgram(vfProgram);

	return vfProgram;
}
void init(GLFWwindow* window) {
	renderingProgram = createShaderProgram();
	glGenVertexArrays(numVAOs, vao);
	glBindVertexArray(vao[0]);
}

void display(GLFWwindow* window, double currentTime) {
	glUseProgram(renderingProgram);
	glPointSize(30.0f);
	glDrawArrays(GL_POINTS, 0, 1);
}

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

	init(window);
	while (!glfwWindowShouldClose(window)) {
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	glfwDestroyWindow(window);
	exit(EXIT_SUCCESS);
}