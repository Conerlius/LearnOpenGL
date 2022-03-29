#define STB_IMAGE_IMPLEMENTATION
#include "ApplicationStart.h"

/// 启动函数
int main(int argc, char* argv[]) {
	std::string courceIndex = "OpenGL_Session8";
	// 获取参数
	for (int index =1; index < argc; index+=2)
	{
		std::string key_string = std::string(argv[index]);
		if (key_string.compare("-course") == 0)
		{
			courceIndex = "OpenGL_Session" + std::string(argv[index+1]);
		}
	}
	// 启动程序
	ApplicationStart* application = new ApplicationStart();
	int result = application->Start(courceIndex);
	return result;
}