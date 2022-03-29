#pragma once
#include "../CoreMinial.h"
#include "../CourseBase.h"
#include "../CUSTOM_REFLECT_ACTION.h"


class Course1 : public CourseBase {
public:
	Course1();
	virtual ~Course1();
	virtual void Tick(double deltaTime) override;
private:
	float* vertices;
	unsigned int VBO;
};