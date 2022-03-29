#pragma once
#include "UIBase.h"
#include <string>

class MainView : public UIBase {
public:
	MainView(std::string courseIndex);
	virtual void Tick(double deltaTime) override;

private:
	std::string CourseIndex;
};