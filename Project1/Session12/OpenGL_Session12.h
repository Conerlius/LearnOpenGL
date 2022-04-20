#pragma once
#include "../BaseSession.h"

class OpenGL_Session12 : public BaseSession
{
public:
    GENERATE_CREATE(OpenGL_Session12, "环境光")
    virtual void Start(ApplicationStart *application) override;
    virtual void drawView() override;
};
REGISTER(OpenGL_Session12)