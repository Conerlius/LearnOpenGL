#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class OpenGL_Session2
{
public:
	OpenGL_Session2();
	~OpenGL_Session2();
	int Start();
public:
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
private:
	void initGLFW();
	int drawWindow();
	void processInput(GLFWwindow* window);
	//void drawView();
};