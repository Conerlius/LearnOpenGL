#pragma once
#include <vector>
class RenderObject {
public:
	RenderObject();
	virtual ~RenderObject();

	virtual void Render();
	virtual void AddRenderItem(RenderObject* obj);
private:
	std::vector<RenderObject*> Childrens;
};