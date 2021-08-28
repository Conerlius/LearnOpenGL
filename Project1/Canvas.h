#pragma once
#include "RenderBatch.h"
#include "UIBase.h"

class Canvas : public RenderBatch {
public:
	Canvas();
	virtual ~Canvas();

	void Tick(double deltaTime);
	void AddView(UIBase* ui);
};