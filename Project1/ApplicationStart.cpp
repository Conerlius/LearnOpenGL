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
	//它的唯一工作就是在析构函数中删除ApplicationStart的实例
	class Deleter
	{
	public:
		~Deleter()
		{
			if (m_pInstance)
				delete m_pInstance;
		}
	};
	//定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数
	static Deleter deleter;
public:
	// 单例
	static ApplicationStart* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new ApplicationStart();
		return m_pInstance;
	}

	// 启动
	int Start()
	{
		initGLFW();
		BaseSession* session = new OpenGL_Session1();
		session->Start();
		int result = drawWindow(session);
		return result;
	}

	static void Framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		// 设置窗口的维度
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
	// 初始化GLFW
	void initGLFW() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	}

	// 绘制展示页面
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
		//窗口大小被调整的回调
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