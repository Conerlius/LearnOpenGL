#include "RenderBatch.h"

RenderBatch::RenderBatch():Name("default")
{
}

RenderBatch::RenderBatch(const std::string& name):Name(name)
{
}

RenderBatch::~RenderBatch()
{
}

void RenderBatch::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
