﻿#include "OpenGL_Session2.h"
#include "../Configure.h"

using namespace std;

void OpenGL_Session2::Start(ApplicationStart* application)
{
	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};
	shaderId = CompileShader();
	GLuint locationId = glGetAttribLocation(shaderId, "aPos");
	if (Configure::Instance()->EnableOpenGLCore)
	{
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
	}
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(locationId, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(locationId);
}

void OpenGL_Session2::drawView() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glUseProgram(shaderId);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	// 目前就渲染一个，就不用解绑了！
	// glDisableVertexAttribArray(0);
}
// 编译shader
GLuint OpenGL_Session2::CompileShader() {
	const char* vertexShaderSource = R"(#version 330 core
layout(location = 0) in vec3 aPos;
void main()	{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
})";

	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	const char* fragmentShaderSource = R"(#version 330 core
out vec4 FragColor;
void main()	{
		FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);	
})";

	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	return shaderProgram;
}
