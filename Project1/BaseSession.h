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
    BaseSession() {}

    virtual ~BaseSession() {}

    virtual void Start(ApplicationStart *application) {}

    virtual void processInput(GLFWwindow *window) {}

    virtual void drawView() {}
};

#define REGISTER(className)\
className* objectCreator##className(){\
	return new className;\
};\
RegisterAction g_creatorRegister##className(#className,(PTRCreateObject)objectCreator##className);