#pragma once

#include <iostream>
#include <string>
#include "RenderBatch.h"
#include "UIBase.h"
#include "World.h"
#include "Canvas.h"

class Application {
public:
	Application(const std::string& name);
	virtual ~Application();
	void SetViewSize(int width, int height);
	void Init();
	void Loop();
	void Tick(double deltaTime);
	void Destroy();

	void AddViewToViewPort(UIBase* ui);
	void RemoveViewFromViewPort(UIBase* ui);
	void CreateWorld(World* world);

	static Application* Instance();
private:
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void processInput();
private:
	int64_t GetTicks();
	bool IsTerminate;
	std::string AppName;
	Canvas* RootUI;
	World* CurrentWorld;
	int ViewWidth, ViewHeight;
	GLFWwindow* window;
};