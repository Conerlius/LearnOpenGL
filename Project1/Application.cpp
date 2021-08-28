#include "Application.h"
#include "CoreMinial.h"
#include <windows.h>

static Application* _instance;
Application::Application(const std::string& name):AppName(name), ViewWidth(1920), ViewHeight(1080)
{
	IsTerminate = false;
	_instance = this;
}

Application::~Application()
{
}

void Application::SetViewSize(int width, int height)
{
	ViewWidth = width;
	ViewHeight = height;
	if(window)
		glViewport(0, 0, width, height);
}

void Application::Init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if MAC_OS
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	window = glfwCreateWindow(ViewWidth, ViewHeight, AppName.c_str(), NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}
	glViewport(0, 0, ViewWidth, ViewHeight);
	glfwSetFramebufferSizeCallback(window, &Application::framebuffer_size_callback);

}

void Application::Loop()
{
	LARGE_INTEGER perFrequenc;
	QueryPerformanceFrequency(&perFrequenc);
	double perQuadPart = (double)perFrequenc.QuadPart;
	int64_t start, finish, deltaTime=0;
	while (!IsTerminate)
	{
		start = GetTicks();
		Tick(deltaTime / perQuadPart);
		finish = GetTicks();
		deltaTime = finish - start;
		//todo: 应该有最小的更新时间的
		//Sleep(0);
	}
	glfwTerminate();
}

void Application::Tick(double deltaTime)
{
	IsTerminate = glfwWindowShouldClose(window);
	processInput();

	if (RootUI)
	{
		RootUI->Tick(deltaTime);
	}
	if (CurrentWorld) {
		CurrentWorld->Tick(deltaTime);
		CurrentWorld->Render();
	}
	if (RootUI)
	{
		RootUI->Render();
	}

	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Application::Destroy()
{
	SafeDelete(RootUI);
	SafeDelete(CurrentWorld);
}

void Application::AddViewToViewPort(UIBase* ui)
{
	if (RootUI == nullptr) {
		RootUI = new Canvas();
	}
	RootUI->AddView(ui);
}

void Application::RemoveViewFromViewPort(UIBase* ui)
{
	if (RootUI) {
		RootUI->RemoveView(ui);
	}
}

void Application::CreateWorld(World* world)
{
	if (CurrentWorld) {
		SafeDelete(CurrentWorld);
	}
	CurrentWorld = world;
}

Application* Application::Instance()
{
	return _instance;
}

void Application::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	if (_instance)
		_instance->SetViewSize(width, height);
}

void Application::processInput()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int64_t Application::GetTicks()
{
	LARGE_INTEGER ticks;
	if (!QueryPerformanceCounter(&ticks))
	{
		return 0LL;
	}
	return ticks.QuadPart;
}
