#pragma once
#include "../BaseSession.h"

class OpenGL_Session3:public BaseSession
{
public:
	GENERATE_CREATE(OpenGL_Session3, "简单实用 buffer")
	void Start(ApplicationStart* application);
	void drawView();
    
private:
	GLuint VAO,VBO, EBO;
};
REGISTER(OpenGL_Session3)