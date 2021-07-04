#pragma once
#include "../BaseSession.h"

class OpenGL_Session6 : public BaseSession
{
public:
	OpenGL_Session6();
	~OpenGL_Session6();
	void Start(ApplicationStart* application);
	void processInput(GLFWwindow* window);
	void drawView();
    
private:
	GLuint VBO, VAO;
};

REGISTER(OpenGL_Session6)