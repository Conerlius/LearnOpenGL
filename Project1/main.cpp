#define STB_IMAGE_IMPLEMENTATION
#include "Application.h"
#include "AllCourse.h"

/// 启动函数
int main(int argc, char* argv[]) {
	const std::string name = "OpenGL 教程";
	std::string courceIndex = "Course1";
	// 获取有用的参数
	for (int index=0; index <= argc; index+=2)
	{
		std::string key_string = std::string(argv[index]);
		if (key_string.compare("-course") == 0)
		{
			courceIndex = "Course" + std::string(argv[index+1]);
		}
	}
	// 创建一个窗口
	Application* app = new Application(name);
	app->CreateWorld(World::Default());
	app->AddViewToViewPort(new MainView(courceIndex));
	app->Init();
	app->Loop();
	app->Destroy();
	return 0;
}