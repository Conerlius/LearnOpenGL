#pragma once
#include "../BaseSession.h"

class OpenGL_Session6 : public BaseSession
{
public:
	GENERATE_CREATE(OpenGL_Session6, "更新uniform")
	void Start(ApplicationStart* application);
	void drawView();
    
private:
	GLuint VBO, VAO;
};

REGISTER(OpenGL_Session6)