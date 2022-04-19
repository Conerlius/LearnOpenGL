#version 330 core
out vec3 FragColor;

in vec3 fragmentColor;

void main()
{
	FragColor = fragmentColor;
}