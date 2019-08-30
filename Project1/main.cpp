#include "ApplicationStart.h"

/// 启动函数
int main() {
	// 创建一个程序实例
	ApplicationStart* application = new ApplicationStart();//ApplicationStart::GetInstance();
	int result = application->Start();
	return result;
}