#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class ApplicationStart;

class BaseSession
{
public:
	BaseSession() 
	{}
	~BaseSession()
	{}
	virtual void Start(ApplicationStart* application)
	{}
	virtual void processInput(GLFWwindow* window)
	{}
	virtual void drawView()
	{}
};