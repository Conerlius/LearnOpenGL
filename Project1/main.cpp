#include "ApplicationStart.h"

/// ��������
int main() {
	// ����һ������ʵ��
	ApplicationStart* application = new ApplicationStart();//ApplicationStart::GetInstance();
	int result = application->Start();
	return result;
}