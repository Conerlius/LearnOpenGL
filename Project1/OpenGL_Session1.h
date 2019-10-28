#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "BaseSession.h"

class OpenGL_Session1 : public BaseSession
{
private:
	GLuint VAO, VBO;
public:
	OpenGL_Session1();
	~OpenGL_Session1();
	void Start(ApplicationStart* application);
	void processInput(GLFWwindow* window);
	void drawView();
};