#include "OpenGL_Session1_1.h"

using namespace std;

GLuint vertexArray;
OpenGL_Session1_1::OpenGL_Session1_1() {
}
OpenGL_Session1_1::~OpenGL_Session1_1() {
}
void OpenGL_Session1_1::Start(ApplicationStart* application)
{
	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};
	
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void OpenGL_Session1_1::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void OpenGL_Session1_1::drawView() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(vertexArray);
	UseShader();

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}

void OpenGL_Session1_1::UseShader() {
	const char* vertexShaderSource = R"(#version 330 core
layout(location = 0) in vec3 aPos;
void main()	{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
})";

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	const char* fragmentShaderSource = R"(#version 330 core
out vec4 FragColor;
void main()	{
		FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);	
})";

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glUseProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
