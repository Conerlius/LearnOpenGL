#pragma once
#include "../BaseSession.h"

class OpenGL_Session2 : public BaseSession
{
private:
	GLuint VAO, VBO, shaderId;
public:
	GENERATE_CREATE(OpenGL_Session2, "简单实用 shader")
	void Start(ApplicationStart* application);
	void drawView();
    
private:
	GLuint CompileShader();
};
REGISTER(OpenGL_Session2)