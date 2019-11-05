#include <iostream>
#include "ApplicationStart.h"
#include "Session1/OpenGL_Session1.h"
#include "Session2/OpenGL_Session2.h"
#include "Session3/OpenGL_Session3.h"
#include "Session4/OpenGL_Session4.h"
#include "Session5/OpenGL_Session5.h"
#include "Session6/OpenGL_Session6.h"
#include "Session7/OpenGL_Session7.h"

using namespace std;

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
	// 预编译shader
	OpenGL_Tools::GetInstance()->CompileShader("Shaders/BaseVertex.shader", "Shaders/BaseFragment.shader", "BaseShader");
	while (!glfwWindowShouldClose(window))
	{
		// 主页
		if (m_curSession == NULL) {
			this->DrawAllSessions();
		}
		else {
			this->DrawBackMenu();
			m_curSession->processInput(window);
			m_curSession->drawView();
		}
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	// 销毁窗口
	glfwTerminate();
	return 0;
}
void ApplicationStart::DrawAllSessions() {
	m_curSession = new OpenGL_Session7();
	m_curSession->Start(this);
}
void ApplicationStart::DrawBackMenu() {

}