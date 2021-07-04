#pragma once
#include "../Session9/OpenGL_Session9.h"

class OpenGL_Session10 : public OpenGL_Session9
{
public:
	OpenGL_Session10();
	~OpenGL_Session10();
	void Start(ApplicationStart* application);
	void drawView();
    
};
//REGISTER(OpenGL_Session10)