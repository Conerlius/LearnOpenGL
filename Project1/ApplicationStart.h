#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class ApplicationStart
{
public:
	void (*framebuffer_size_callback)(GLFWwindow* window, int width, int height) = NULL;

//private:
//	static ApplicationStart* m_pInstance;
//	//����Ψһ��������������������ɾ��ApplicationStart��ʵ��
//	class Deleter
//	{
//	public:
//		~Deleter()
//		{
//			if (m_pInstance)
//				delete m_pInstance;
//		}
//	};
//	//����һ����̬��Ա�������������ʱ��ϵͳ���Զ�����������������
//	static Deleter deleter;
	//BaseSession *m_curSession;


public:
	// ����
	/*static ApplicationStart* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new ApplicationStart();
		return m_pInstance;
	}*/

	// ����
	int Start();

	static void Framebuffer_size_callback(GLFWwindow* window, int width, int height);
	ApplicationStart();

private:
	//ApplicationStart();
	~ApplicationStart();
	// ��ʼ��GLFW
	void initGLFW();

	// ����չʾҳ��
	int drawWindow();
	void DrawAllSessions();
	void DrawBackMenu();
};