#define STB_IMAGE_IMPLEMENTATION
#include "ApplicationStart.h"

/// ��������
int main() {
	// ����һ������ʵ��
	ApplicationStart* application = new ApplicationStart();
	int result = application->Start();
	return result;
}