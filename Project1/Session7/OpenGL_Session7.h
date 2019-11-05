#pragma once
#include "../BaseSession.h"

class OpenGL_Session7 : public BaseSession
{
public:
	OpenGL_Session7();
	~OpenGL_Session7();
	void Start(ApplicationStart* application);
	void processInput(GLFWwindow* window);
	void drawView();

private:
	GLuint VBO, VAO;
};