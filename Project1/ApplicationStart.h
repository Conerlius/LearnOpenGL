#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "BaseSession.h"

class ApplicationStart
{
public:
	void (*framebuffer_size_callback)(GLFWwindow* window, int width, int height) = NULL;
	BaseSession* m_curSession = NULL;
public:

	// ����
	int Start();

	static void Framebuffer_size_callback(GLFWwindow* window, int width, int height);
	ApplicationStart();
	~ApplicationStart();

private:
	// ��ʼ��GLFW
	int initGLFW();

	// ����չʾҳ��
	int drawWindow();
	void DrawAllSessions();
	void DrawBackMenu();
};