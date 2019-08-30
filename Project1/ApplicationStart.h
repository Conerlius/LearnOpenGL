#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class ApplicationStart
{
public:
	void (*framebuffer_size_callback)(GLFWwindow* window, int width, int height) = NULL;

//private:
//	static ApplicationStart* m_pInstance;
//	//它的唯一工作就是在析构函数中删除ApplicationStart的实例
//	class Deleter
//	{
//	public:
//		~Deleter()
//		{
//			if (m_pInstance)
//				delete m_pInstance;
//		}
//	};
//	//定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数
//	static Deleter deleter;
	//BaseSession *m_curSession;


public:
	// 单例
	/*static ApplicationStart* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new ApplicationStart();
		return m_pInstance;
	}*/

	// 启动
	int Start();

	static void Framebuffer_size_callback(GLFWwindow* window, int width, int height);
	ApplicationStart();

private:
	//ApplicationStart();
	~ApplicationStart();
	// 初始化GLFW
	void initGLFW();

	// 绘制展示页面
	int drawWindow();
	void DrawAllSessions();
	void DrawBackMenu();
};