#pragma once
#include "RenderBatch.h"
#include "UIBase.h"
#include <vector>

class Canvas : public RenderBatch {
public:
	Canvas();
	virtual ~Canvas();

	void Tick(double deltaTime);
	void AddView(UIBase* ui);
	void RemoveView(UIBase* ui);
	virtual void Render() override;
private:
	std::vector<UIBase*> UIStack;
};