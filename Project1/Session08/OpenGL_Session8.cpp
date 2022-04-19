#include "OpenGL_Session8.h"


void OpenGL_Session8::Start(ApplicationStart* application)
{
	// 预编译shader
	OpenGL_Tools::GetInstance()->CompileShader("Shaders/Session08/Session8_Vertex.shader", "Shaders/Session08/Session8_Fragment.shader", "Session8Shader");
	// 加载图片
	texture1 = OpenGL_Tools::GetInstance()->LoadTexture("container.jpg");
	texture2 = OpenGL_Tools::GetInstance()->LoadTexture("awesomeface.png");
	float vertices[] = {
		//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
	};
	unsigned int indices[] = { // 注意索引从0开始! 
		0, 1, 3, // 第一个三角形
		1, 2, 3, // 第二个三角形
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// 定点
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)0);
	glEnableVertexAttribArray(0);
	// 颜色
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

void OpenGL_Session8::drawView()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// 不需要也能生效，这个要查一下
	// glBindTexture(GL_TEXTURE_2D, texture1);
	// glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1);
	// glActiveTexture(GL_TEXTURE1);
	// glBindTexture(GL_TEXTURE_2D, texture2);
	glBindVertexArray(VAO);

	GLuint shaderProgram = OpenGL_Tools::GetInstance()->UseShader("Session8Shader");
	//ourShader.use(); // 别忘记在激活着色器前先设置uniform！
	//glUniform1i(glGetUniformLocation(shaderProgram, "texture1"), 0); // 手动设置
	//glUniform1i(glGetUniformLocation(shaderProgram, "texture2"), 1); // 或者使用着色器类设置

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
