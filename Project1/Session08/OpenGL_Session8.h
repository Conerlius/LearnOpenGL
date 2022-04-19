#pragma once
#include "../BaseSession.h"

class OpenGL_Session8 : public BaseSession
{
public:
	GENERATE_CREATE(OpenGL_Session8, "纹理使用")
	void Start(ApplicationStart* application);
	void drawView();
    
private:
	GLuint VBO, VAO;
	GLuint texture1, texture2;
};
REGISTER(OpenGL_Session8)