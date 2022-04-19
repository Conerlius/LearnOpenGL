#pragma once
#include "../BaseSession.h"

class OpenGL_Session11 : BaseSession
{
public:
    GENERATE_CREATE(OpenGL_Session11, "灯光数据的透传")

    virtual void Start(ApplicationStart *application) override;
    virtual void drawView() override;
};
REGISTER(OpenGL_Session11)