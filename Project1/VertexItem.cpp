#include "Base/VertexItem.h"
#include <glad\glad.h>

void VertexItem::SetVertices(std::vector<float> vertices)
{
	Vertices = vertices;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &Vertices, GL_STATIC_DRAW);
}
