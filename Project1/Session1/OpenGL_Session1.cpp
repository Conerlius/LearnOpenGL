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
	shaderId = OpenGL_Tools::GetInstance()->UseShader("BaseShader");
	attPos = glGetAttribLocation(shaderId, "aPos");
	
	#if OpenGL_Session1_Use_Array
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	#else
	glGenBuffers(1, &VBO);
	//把顶点数组复制到缓冲中供OpenGL使用
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(attPos, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray( attPos );
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	#endif
}

void OpenGL_Session1::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
// 绘制

void OpenGL_Session1::drawView() {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(shaderId);
	#if OpenGL_Session1_Use_Array
	// glVertexAttribPointer(attPos, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	#else
	// 指定VBO
	// glBindBuffer( GL_ARRAY_BUFFER, VBO );
	// // // 设置顶点属性指针
	// glVertexAttribPointer(attPos, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	#endif
	// 启动数组
	// glEnableVertexAttribArray( attPos );
	// 绘制三角形
	glDrawArrays(GL_TRIANGLES, 0, 3);
	// glBindBuffer(GL_ARRAY_BUFFER, 0);
}