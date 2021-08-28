#include "Application.h"
#include "CoreMinial.h"
#include <windows.h>

Application::Application(const std::string& name):AppName(name)
{
	IsTerminate = false;
}

Application::~Application()
{
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
	}
}

void Application::Tick(double deltaTime)
{
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

void Application::CreateWorld(World* world)
{
	if (CurrentWorld) {
		SafeDelete(CurrentWorld);
	}
	CurrentWorld = world;
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
