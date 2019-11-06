#pragma once
#include "../BaseSession.h"
#include "../stb_image.h"

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