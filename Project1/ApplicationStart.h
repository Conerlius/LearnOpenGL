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

	// 启动
	int Start(string courceIndex);

	static void Framebuffer_size_callback(GLFWwindow* window, int width, int height);
	ApplicationStart();
	~ApplicationStart();

private:
	// 初始化GLFW
	int initGLFW();

	// 绘制展示页面
	int drawWindow();
	void DrawAllSessions();
	void DrawBackMenu();
	string CourceIndex;
};