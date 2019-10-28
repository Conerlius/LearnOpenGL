#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "BaseSession.h"

class OpenGL_Session1_1 : public BaseSession
{
public:
	OpenGL_Session1_1();
	~OpenGL_Session1_1();
	void Start(ApplicationStart* application);
	void processInput(GLFWwindow* window);
	void drawView();
private:
	void UseShader();
};