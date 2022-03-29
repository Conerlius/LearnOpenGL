#pragma once

#include "../RenderObject.h"

class VertexItem : public RenderObject
{
public:
	virtual void SetVertices(std::vector<float> vertices);
private:
	std::vector<float> Vertices;
	unsigned int VBO;
};

