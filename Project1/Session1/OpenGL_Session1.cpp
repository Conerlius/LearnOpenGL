#include "OpenGL_Session1.h"

using namespace std;


// 只是绘制一个三角形

OpenGL_Session1::OpenGL_Session1() {
}
OpenGL_Session1::~OpenGL_Session1() {
}
// 声明一下要使用的VAO和VBO
// 使用无符号short性能更优

void OpenGL_Session1::Start(ApplicationStart* application)
{
	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};
	// 生成VAO
	glGenVertexArrays(1, &VAO);
	// 绑定VAO
	glBindVertexArray(VAO);
	// 生成VBO
	glGenBuffers(1, &VBO);
	// 把顶点数组复制到缓冲中供OpenGL使用
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 设置顶点属性指针
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// 启动数组
	glEnableVertexAttribArray(0);
}

void OpenGL_Session1::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
// 绘制
void OpenGL_Session1::drawView() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	// 指定VAO
	glBindVertexArray(VAO);
	// 绘制三角形
	glDrawArrays(GL_TRIANGLES, 0, 3);
}