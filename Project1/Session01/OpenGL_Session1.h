#pragma once
#include "../BaseSession.h"
#include "../stb_image.h"

class OpenGL_Session1 : public BaseSession
{
private:
//#if OpenGL_Session1_Use_Array
	GLuint VAO;
//#else
	GLuint VBO;
//#endif
	GLuint shaderId;
	GLuint attPos;
public:
	GENERATE_CREATE(OpenGL_Session1, "简单三角形绘制")
	void Start(ApplicationStart* application);
	void drawView();
    
};
REGISTER(OpenGL_Session1)