#pragma once
#include "UIItem.h"

class UIBase : public UIItem {
public:
	UIBase();
	virtual ~UIBase();
	virtual void Tick(double deltaTime);
};