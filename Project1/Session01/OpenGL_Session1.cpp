#include "OpenGL_Session1.h"

#include "../Configure.h"

using namespace std;

// 声明一下要使用的VAO和VBO
// 使用无符号short性能更优
void OpenGL_Session1::Start(ApplicationStart* application)
{
	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};
	attPos = 0;
	if (Configure::Instance()->EnableOpenGLCore)
	{
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
	}
	glGenBuffers(1, &VBO);
	//把顶点数组复制到缓冲中供OpenGL使用
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(attPos, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray( attPos );

}
// 绘制
void OpenGL_Session1::drawView() {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	// 绘制三角形
	glDrawArrays(GL_TRIANGLES, 0, 3);
}