#pragma once

#include <string>
#include "CourseManager.h"

class CUSTOM_REFLECT_ACTION {
public:
	CUSTOM_REFLECT_ACTION(std::string name, CUSTOM_REFLECT_COURSE_FUNCTION ctr) {
		CourseManager::AddReflectionCourse(name, ctr);
	}
};