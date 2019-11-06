#include "OpenGL_Session8.h"

OpenGL_Session8::OpenGL_Session8()
{
}

OpenGL_Session8::~OpenGL_Session8()
{
}

void OpenGL_Session8::Start(ApplicationStart* application)
{
	// Ԥ����shader
	OpenGL_Tools::GetInstance()->CompileShader("Shaders/Session8/Session8_Vertex.shader", "Shaders/Session8/Session8_Fragment.shader", "Session8Shader");
	// ����ͼƬ
	texture1 = OpenGL_Tools::GetInstance()->LoadTexture("container.jpg");
	texture2 = OpenGL_Tools::GetInstance()->LoadTexture("awesomeface.png");
	float vertices[] = {
		//     ---- λ�� ----       ---- ��ɫ ----     - �������� -
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // ����
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // ����
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // ����
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // ����
	};
	unsigned int indices[] = { // ע��������0��ʼ! 
		0, 1, 3, // ��һ��������
		1, 2, 3, // �ڶ���������
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// ����
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(0);
	// ��ɫ
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(1);
	// uv
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)(6 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(2);
	
	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}
void OpenGL_Session8::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
void OpenGL_Session8::drawView()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// ����ҪҲ����Ч�����Ҫ��һ��
	// glBindTexture(GL_TEXTURE_2D, texture1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glBindVertexArray(VAO);

	GLuint shaderProgram = OpenGL_Tools::GetInstance()->UseShader("Session8Shader");
	//ourShader.use(); // �������ڼ�����ɫ��ǰ������uniform��
	glUniform1i(glGetUniformLocation(shaderProgram, "texture1"), 0); // �ֶ�����
	glUniform1i(glGetUniformLocation(shaderProgram, "texture2"), 1); // ����ʹ����ɫ��������

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}