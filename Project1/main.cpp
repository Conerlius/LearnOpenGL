#define STB_IMAGE_IMPLEMENTATION
#include "Application.h"
#include "MainView.h"
/// 启动函数
int main() {
	const std::string name = "OpenGL 教程";
	// 创建一个窗口
	Application* app = new Application(name);
	app->CreateWorld(World::Default());
	app->AddViewToViewPort(new MainView());
	app->Loop();
	app->Destroy();
	return 0;
}