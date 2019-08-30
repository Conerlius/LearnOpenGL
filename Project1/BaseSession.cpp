#include <glad/glad.h>
#include <GLFW/glfw3.h>

class BaseSession
{
public:
	BaseSession()
	{}
	~BaseSession()
	{}
	virtual void Start() = 0;
	virtual void processInput(GLFWwindow* window) = 0;
	virtual void drawView() = 0;
};

