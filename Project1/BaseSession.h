#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "OpenGL_Tools.h"
#include "RegisterAction.h"

class ApplicationStart;

#define GENERATE_CREATE(className, DES) className() \
{ \
_name = u8##DES; \
}


class BaseSession {
public:
    GENERATE_CREATE(BaseSession, "BaseSession")

    virtual std::string Name(){return _name;}
    virtual void Start(ApplicationStart *application) {}
    virtual void drawView() {}
    virtual void processInput(GLFWwindow *window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

public:
    std::string _name;
};

#define REGISTER(className)\
className* objectCreator##className(){\
	return new className;\
};\
RegisterAction g_creatorRegister##className(#className,(PTRCreateObject)objectCreator##className);

