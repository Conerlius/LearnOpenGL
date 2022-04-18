#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "OpenGL_Tools.h"
#include "RegisterAction.h"

class ApplicationStart;

class BaseSession {
public:
    BaseSession()
    {
        _name = "BaseSession";
    }

    virtual ~BaseSession() {}

    virtual string Name(){return _name;}
    virtual void Start(ApplicationStart *application) {}

    virtual void processInput(GLFWwindow *window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

    virtual void drawView() {}
public:
    string _name;
};

#define REGISTER(className)\
className* objectCreator##className(){\
	return new className;\
};\
RegisterAction g_creatorRegister##className(#className,(PTRCreateObject)objectCreator##className);