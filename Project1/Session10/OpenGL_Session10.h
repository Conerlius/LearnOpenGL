#pragma once
#include "../BaseSession.h"

class OpenGL_Session10 : public BaseSession
{
public:
	GENERATE_CREATE(OpenGL_Session10, "立方体纹理")
	void Start(ApplicationStart* application);
	void drawView();
protected:
	GLuint VBO, VAO;
	GLuint texture1, texture2;
	glm::mat4 mvp;
};
REGISTER(OpenGL_Session10)