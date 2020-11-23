#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 vertexColor;
layout (location = 2) in vec2 myuv;

uniform mat4 MVP;

out vec3 fragmentColor;
out vec2 uvmap;

void main()
{
    gl_Position = MVP * vec4(aPos, 1.0);
    fragmentColor = vertexColor;
    uvmap = myuv;
}