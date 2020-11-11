#include "OpenGL_Session1.h"

using namespace std;


// ֻ�ǻ���һ��������

OpenGL_Session1::OpenGL_Session1() {
}
OpenGL_Session1::~OpenGL_Session1() {
}
// ����һ��Ҫʹ�õ�VAO��VBO
// ʹ���޷���short���ܸ���

void OpenGL_Session1::Start(ApplicationStart* application)
{
	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};
	// ����VAO
	glGenVertexArrays(1, &VAO);
	// ��VAO
	glBindVertexArray(VAO);
	// ����VBO
	glGenBuffers(1, &VBO);
	// �Ѷ������鸴�Ƶ������й�OpenGLʹ��
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// ���ö�������ָ��
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// ��������
	glEnableVertexAttribArray(0);
}

void OpenGL_Session1::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
// ����
void OpenGL_Session1::drawView() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	// ָ��VAO
	glBindVertexArray(VAO);
	// ����������
	glDrawArrays(GL_TRIANGLES, 0, 3);
}