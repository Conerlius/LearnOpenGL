#pragma once
#include "../BaseSession.h"

class OpenGL_Session5 : public BaseSession
{
public:
	OpenGL_Session5();
	~OpenGL_Session5();
	void Start(ApplicationStart* application);
	void drawView();
    
private:
	GLuint VBO, VAO;
};
REGISTER(OpenGL_Session5)