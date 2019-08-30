#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "OpenGL_Session1.h"
#include "OpenGL_Session2.h"

using namespace std;

class ApplicationStart
{
public:
	void (*framebuffer_size_callback)(GLFWwindow* window, int width, int height) = NULL;

private:
	static ApplicationStart* m_pInstance;
	//����Ψһ��������������������ɾ��ApplicationStart��ʵ��
	class Deleter
	{
	public:
		~Deleter()
		{
			if (m_pInstance)
				delete m_pInstance;
		}
	};
	//����һ����̬��Ա�������������ʱ��ϵͳ���Զ�����������������
	static Deleter deleter;
public:
	// ����
	static ApplicationStart* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new ApplicationStart();
		return m_pInstance;
	}

	// ����
	int Start()
	{
		initGLFW();
		BaseSession* session = new OpenGL_Session1();
		session->Start();
		int result = drawWindow(session);
		return result;
	}

	static void Framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		// ���ô��ڵ�ά��
		glViewport(0, 0, width, height);
		if (m_pInstance == NULL)
			return;

		if (m_pInstance->framebuffer_size_callback != NULL) {
			m_pInstance->framebuffer_size_callback(window, width, height);
		}
	}
private:
	ApplicationStart()
	{
	}
	~ApplicationStart()
	{
	}
	// ��ʼ��GLFW
	void initGLFW() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	}

	// ����չʾҳ��
	int drawWindow(BaseSession* session) {
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
			session->processInput(window);
			session->drawView();

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwTerminate();
		return 0;
	}
};