#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class BaseSession;

class ApplicationStart
{
public:
	void (*framebuffer_size_callback)(GLFWwindow* window, int width, int height) = NULL;
	BaseSession *m_curSession;


public:
	// 启动
	int Start();

	static void Framebuffer_size_callback(GLFWwindow* window, int width, int height);
	ApplicationStart();

private:
	~ApplicationStart();
	// 初始化GLFW
	void initGLFW();

	// 绘制展示页面
	int drawWindow();
	void DrawAllSessions();
	void DrawBackMenu();
};