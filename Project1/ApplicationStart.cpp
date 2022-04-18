#include <iostream>
#include "ApplicationStart.h"
#include "Configure.h"

using namespace std;

ApplicationStart::ApplicationStart()
{
	IsInit = false;
}

ApplicationStart::~ApplicationStart()
{
}

void ApplicationStart::Configure()
{
	if (initGLFW() != 0) {
		IsInit = false;
		return;
	}
	Window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (Window == NULL) {
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(Window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return;
	}
	//窗口大小被调整的回调
	glfwSetFramebufferSizeCallback(Window, Framebuffer_size_callback);
	// 预编译shader
	// OpenGL_Tools::GetInstance()->CompileShader("Shaders/BaseVertex.shader", "Shaders/BaseFragment.shader", "BaseShader");
	
	IsInit = true;
}

// 设置窗口的维度
// 如果不重置的话，导致opengl画的界面没有全屏
void ApplicationStart::Framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	// 设置窗口的维度
	glViewport(0, 0, width, height);
}

// 初始化GLFW
int ApplicationStart::initGLFW() {
	if (!glfwInit()) {
		return -1;
	}
	// 4倍抗锯齿
	glfwWindowHint(GLFW_SAMPLES, 4);
	// opengl的版本
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// 直接声明使用opengl core
	if (Configure::Instance().EnableOpenGLCore)
	{
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}
	else
	{
		// 如果不想显性创建一个VAO的话，就开启这个
		// https://blog.csdn.net/McQueen_LT/article/details/119515149
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	}
#if MAC_OS
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	return 0;
}

// 启动
int ApplicationStart::Start()
{
	auto courceIndex = "OpenGL_Session" + std::to_string(Configure::Instance().DefaultClassIndex);
	m_curSession = (BaseSession*)SessionMgr::getInstance().getClassByName(courceIndex);
	m_curSession->Start(this);
	// 画
	int result = drawWindow();
	return result;
}

// 绘制展示页面
int ApplicationStart::drawWindow() {
	while (!glfwWindowShouldClose(Window))
	{
		m_curSession->processInput(Window);
		m_curSession->drawView();
		// 检查触发事件
		glfwPollEvents();
		// 交换颜色缓冲
		glfwSwapBuffers(Window);
	}
	// 销毁窗口
	glfwTerminate();
	return 0;
}