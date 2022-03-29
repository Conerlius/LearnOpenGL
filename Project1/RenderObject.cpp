#include "RenderObject.h"

RenderObject::RenderObject()
{
}

RenderObject::~RenderObject()
{
}

void RenderObject::Render()
{
}

void RenderObject::AddRenderItem(RenderObject* obj)
{
	Childrens.push_back(obj);
}
