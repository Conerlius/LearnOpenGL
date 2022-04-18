#pragma once
#include "../BaseSession.h"

class OpenGL_Session2 : public BaseSession
{
private:
	GLuint VAO, VBO, shaderId;
public:
	OpenGL_Session2();
	~OpenGL_Session2();
	void Start(ApplicationStart* application);
	void drawView();
    
private:
	GLuint CompileShader();
};
REGISTER(OpenGL_Session2)