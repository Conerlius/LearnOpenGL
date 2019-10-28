#include "OpenGL_Session3.h"

using namespace std;

OpenGL_Session3::OpenGL_Session3()
{
}
OpenGL_Session3::~OpenGL_Session3()
{
}
int OpenGL_Session3::Start()
{
	this->initGLFW();
	int result = this->drawWindow();
	return result;
}
void OpenGL_Session3::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	// 设置窗口的维度
	glViewport(0, 0, width, height);
}

void OpenGL_Session3::initGLFW() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}
int OpenGL_Session3::drawWindow() {
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
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	while (!glfwWindowShouldClose(window))
	{
		this->processInput(window);
	}
	return 0;
}


void OpenGL_Session3::processInput(GLFWwindow* window) {
}

