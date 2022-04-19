#pragma once
#include "../BaseSession.h"

class OpenGL_Session7 : public BaseSession
{
public:
	GENERATE_CREATE(OpenGL_Session7, "顶点着色")
	void Start(ApplicationStart* application);
	void drawView();
    
private:
	GLuint VBO, VAO;
};
REGISTER(OpenGL_Session7)