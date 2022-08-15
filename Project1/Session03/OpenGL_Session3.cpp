#include "OpenGL_Session3.h"

#include "../Configure.h"

using namespace std;


void OpenGL_Session3::Start(ApplicationStart* application)
{
	float vertices[] = {
		0.5f, 0.5f, 0.0f,   // 右上角
		0.5f, -0.5f, 0.0f,  // 右下角
		-0.5f, -0.5f, 0.0f, // 左下角
		-0.5f, 0.5f, 0.0f   // 左上角
		};
	GLuint indices[] = { // 注意索引从0开始! 
		0, 1, 3, // 第一个三角形
		1, 2, 3  // 第二个三角形
		};
	OpenGL_Tools::GetInstance()->CompileShader("Shaders/Session03/Session3_Vertex.shader", "Shaders/Session03/Session3_Fragment.shader", "Session3Shader");
	GLuint shaderId = OpenGL_Tools::GetInstance()->GetShader("Session3Shader");
	GLuint locationId = glGetAttribLocation(shaderId, "aPos");
	if(Configure::Instance()->EnableOpenGLCore)
	{
		glGenVertexArrays(1, &VAO);
		// 1. 绑定顶点数组对象
		glBindVertexArray(VAO);
	}
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// 2. 把我们的顶点数组复制到一个顶点缓冲中，供OpenGL使用
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3. 复制我们的索引数组到一个索引缓冲中，供OpenGL使用
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	// 4. 设定顶点属性指针
	glVertexAttribPointer(locationId, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(locationId);

}
void OpenGL_Session3::drawView()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	OpenGL_Tools::GetInstance()->UseShader("Session3Shader");
	// glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	// 线框模式
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	// 恢复填充模式
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}