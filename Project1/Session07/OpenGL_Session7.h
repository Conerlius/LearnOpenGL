#pragma once
#include "../BaseSession.h"

class OpenGL_Session7 : public BaseSession
{
public:
	OpenGL_Session7();
	~OpenGL_Session7();
	void Start(ApplicationStart* application);
	void drawView();
    
private:
	GLuint VBO, VAO;
};
REGISTER(OpenGL_Session7)