#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "BaseSession.h"

class OpenGL_Session2 : public BaseSession
{
private:
	GLuint VAO, VBO;
	float vertices[];
public:
	OpenGL_Session2();
	~OpenGL_Session2();
	void Start(ApplicationStart* application);
	void processInput(GLFWwindow* window);
	void drawView();
private:
	void UseShader();
};