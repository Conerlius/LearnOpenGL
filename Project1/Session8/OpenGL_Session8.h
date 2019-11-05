#pragma once
#include "../BaseSession.h"

class OpenGL_Session8 : public BaseSession
{
public:
	OpenGL_Session8();
	~OpenGL_Session8();
	void Start(ApplicationStart* application);
	void processInput(GLFWwindow* window);
	void drawView();

private:
	GLuint VBO, VAO;
};