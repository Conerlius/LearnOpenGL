#pragma once
#include "../BaseSession.h"

class OpenGL_Session4 : public BaseSession
{
public:
	GENERATE_CREATE(OpenGL_Session4, "简单的立方体")
	void Start(ApplicationStart* application);
	void drawView();
    
private:
	GLuint VBO, VAO;
};
REGISTER(OpenGL_Session4)