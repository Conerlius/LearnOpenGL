#include "OpenGL_Session6.h"

OpenGL_Session6::OpenGL_Session6()
{
}

OpenGL_Session6::~OpenGL_Session6()
{
}

void OpenGL_Session6::Start(ApplicationStart* application)
{
	// 预编译shader
	OpenGL_Tools::GetInstance()->CompileShader("Shaders/Session6/Session6_Vertex.shader", "Shaders/Session6/Session6_Fragment.shader", "Session6Shader");
	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};

	unsigned int indices[] = { // 注意索引从0开始! 
		0, 1, 2, // 第一个三角形
	};
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	
	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(0);
}
void OpenGL_Session6::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
void OpenGL_Session6::drawView()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(VAO);

	GLuint shaderProgram = OpenGL_Tools::GetInstance()->UseShader("Session6Shader");

	// 更新uniform颜色
	float timeValue = glfwGetTime();
	float greenValue = sin(timeValue) / 2.0f + 0.5f;
	int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

}