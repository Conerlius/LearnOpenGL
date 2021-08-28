#pragma once
#include "UIBase.h"

class MainView : public UIBase {
public:
	MainView();
	virtual void Tick(double deltaTime) override;
};