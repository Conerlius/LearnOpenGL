#include <iostream>
#include "ApplicationStart.h"
#include "BaseSession.h"
#include "OpenGL_Session1.h"
#include "OpenGL_Session2.h"

using namespace std;

// ����
int ApplicationStart::Start()
{
	initGLFW();
	int result = drawWindow();
	return result;
}

void ApplicationStart::Framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	// ���ô��ڵ�ά��
	glViewport(0, 0, width, height);
	/*if (m_pInstance == NULL)
		return;

	if (m_pInstance->framebuffer_size_callback != NULL) {
		m_pInstance->framebuffer_size_callback(window, width, height);
	}*/
}

ApplicationStart::ApplicationStart()
{
	m_curSession = new OpenGL_Session2();
}
ApplicationStart::~ApplicationStart()
{
}
// ��ʼ��GLFW
void ApplicationStart::initGLFW() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

// ����չʾҳ��
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
	//���ڴ�С�������Ļص�
	glfwSetFramebufferSizeCallback(window, ApplicationStart::Framebuffer_size_callback);
	while (!glfwWindowShouldClose(window))
	{
		// ˢ�±�����ɫ
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// ��ҳ
		if (m_curSession == NULL) {
			this->DrawAllSessions();
		}
		else {
			this->DrawBackMenu();
			m_curSession->processInput(window);
			m_curSession->drawView();
		}
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