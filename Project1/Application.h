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
	void Loop();
	void Tick(double deltaTime);
	void Destroy();

	void AddViewToViewPort(UIBase* ui);
	void CreateWorld(World* world);
private:
	int64_t GetTicks();
	bool IsTerminate;
	std::string AppName;
	Canvas* RootUI;
	World* CurrentWorld;
};