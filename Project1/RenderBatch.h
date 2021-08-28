#pragma once
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class RenderBatch {
public:
	RenderBatch();
	RenderBatch(const std::string& name);
	virtual ~RenderBatch();
	virtual void Render();
private:
	std::string Name;
};