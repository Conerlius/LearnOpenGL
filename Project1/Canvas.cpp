#include "Canvas.h"

Canvas::Canvas()
{
}

Canvas::~Canvas()
{
}

void Canvas::Tick(double deltaTime)
{
	for (const auto& ui : UIStack) {
		ui->Tick(deltaTime);
	}
}

void Canvas::AddView(UIBase* ui)
{
	UIStack.push_back(ui);
}

void Canvas::RemoveView(UIBase* ui)
{
	for (auto it = UIStack.begin(); it != UIStack.end(); it++)
	{
		if (*it == ui) {
			UIStack.erase(it);
			break;
		}
	}
}

void Canvas::Render()
{
	RenderBatch::Render();
	for (const auto& ui : UIStack) {
		ui->Render();
	}
}
