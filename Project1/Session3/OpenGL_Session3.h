#pragma once
#include "../BaseSession.h"

class OpenGL_Session3:public BaseSession
{
public:
	OpenGL_Session3();
	~OpenGL_Session3();
	void Start(ApplicationStart* application);
	void processInput(GLFWwindow* window);
	void drawView();
    
private:
	GLuint VAO,VBO, EBO;
};
REGISTER(OpenGL_Session3)