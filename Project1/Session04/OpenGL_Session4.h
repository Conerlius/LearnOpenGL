#pragma once
#include "../BaseSession.h"

class OpenGL_Session4 : public BaseSession
{
public:
	OpenGL_Session4();
	~OpenGL_Session4();
	void Start(ApplicationStart* application);
	void processInput(GLFWwindow* window);
	void drawView();
    
private:
	GLuint VBO, VAO;
};
REGISTER(OpenGL_Session4)