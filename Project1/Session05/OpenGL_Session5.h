#pragma once
#include "../BaseSession.h"

class OpenGL_Session5 : public BaseSession
{
public:
	GENERATE_CREATE(OpenGL_Session5, "简单实用 buffer 同课3")
	void Start(ApplicationStart* application);
	void drawView();
    
private:
	GLuint VBO, VAO;
};
REGISTER(OpenGL_Session5)