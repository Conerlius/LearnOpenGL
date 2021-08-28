#pragma once
#include <string>

class RenderBatch {
public:
	RenderBatch();
	RenderBatch(const std::string& name);
	virtual ~RenderBatch();
	virtual void Render();
private:
	std::string Name;
};