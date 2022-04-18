#define STB_IMAGE_IMPLEMENTATION
#include <fstream>

#include "ApplicationStart.h"
#include "Configure.h"

std::string& trim(std::string&);

/// 启动函数
int main(int argc, char* argv[]) {
	std::string courceIndex = "OpenGL_Session8";
	// 获取参数
	if(argc >= 2)
	{
		for (int index =1; index < argc; index+=2)
		{
			std::string key_string = std::string(argv[index]);
			if (key_string.compare("-course") == 0)
			{
				courceIndex = "OpenGL_Session" + std::string(argv[index+1]);
			}
		}
	}
	else
	{
		Configure::LoadConfigure();
	}
	// 启动程序
	ApplicationStart* application = new ApplicationStart();
	application->Configure();
	int result = application->Start();
	return result;
}

std::string& trim(std::string&s)
{
	if (s.empty())
	{
		return s;
	}
	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ")+1);
	return s;
}