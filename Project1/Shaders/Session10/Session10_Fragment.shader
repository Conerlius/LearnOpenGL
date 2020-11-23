#version 330 core
out vec4 FragColor;

in vec2 uvmap;
in vec3 fragmentColor;

uniform sampler2D myTextureSampler;

void main()
{
	FragColor = vec4(fragmentColor, 1.0) * texture(myTextureSampler, uvmap);
}