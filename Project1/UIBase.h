#pragma once
#include "RenderBatch.h"

class UIBase : public RenderBatch {
public:
	UIBase();
	virtual ~UIBase();
	void Tick();
};