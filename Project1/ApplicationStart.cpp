#include <iostream>
#include "ApplicationStart.h"

using namespace std;

// 单例
//ApplicationStart* ApplicationStart::GetInstance()
//{
//	if (m_pInstance == NULL)
//		m_pInstance = new ApplicationStart();
//	return m_pInstance;
//}

// 启动
int ApplicationStart::Start()
{
	initGLFW();
	int result = drawWindow();
	return result;
}

void ApplicationStart::Framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	// 设置窗口的维度
	glViewport(0, 0, width, height);
	/*if (m_pInstance == NULL)
		return;

	if (m_pInstance->framebuffer_size_callback != NULL) {
		m_pInstance->framebuffer_size_callback(window, width, height);
	}*/
}

ApplicationStart::ApplicationStart()
{
}
ApplicationStart::~ApplicationStart()
{
}
// 初始化GLFW
void ApplicationStart::initGLFW() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

// 绘制展示页面
int ApplicationStart::drawWindow() {
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
	glfwSetFramebufferSizeCallback(window, ApplicationStart::Framebuffer_size_callback);
	while (!glfwWindowShouldClose(window))
	{
		// 主页
		/*if (m_curSession == NULL) {
			this->DrawAllSessions();
		}
		else {
			this->DrawBackMenu();
			m_curSession->processInput(window);
			m_curSession->drawView();
		}*/
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
void ApplicationStart::DrawAllSessions() {
}
void ApplicationStart::DrawBackMenu() {

}