#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void initGLFW2();
int drawWindow2();
void framebuffer_size_callback2(GLFWwindow* window, int width, int height);
void processInput2(GLFWwindow* window);

int main1()
{
	initGLFW2();
	int result = drawWindow2();
	return result;
}
void initGLFW2() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}
int drawWindow2() {
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return 1;
	}
	//窗口大小被调整的回调
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback2);
	while (!glfwWindowShouldClose(window))
	{
		processInput2(window);
	}
	return 1;
}

void framebuffer_size_callback2(GLFWwindow* window, int width, int height) {
	// 设置窗口的维度
	glViewport(0, 0, width, height);
}

void processInput2(GLFWwindow* window) {
}