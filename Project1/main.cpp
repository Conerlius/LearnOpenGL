#include "ApplicationStart.cpp"

/// ��������
int main() {
	// ����һ������ʵ��
	ApplicationStart* application = ApplicationStart::GetInstance();
	int result = application->Start();
	return result;
}