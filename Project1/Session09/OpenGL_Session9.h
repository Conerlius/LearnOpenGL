#pragma once
#include "../BaseSession.h"

class OpenGL_Session9 : public BaseSession
{
public:
	GENERATE_CREATE(OpenGL_Session9, "MVP的基本使用")
	void Start(ApplicationStart* application);
	void drawView();
protected:
	GLuint VBO, VAO;
	GLuint texture1, texture2;
	glm::mat4 mvp;
};
REGISTER(OpenGL_Session9)
