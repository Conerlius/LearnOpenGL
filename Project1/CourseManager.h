#pragma once
#include <map>
#include "CourseBase.h"

typedef CourseBase* (*CUSTOM_REFLECT_COURSE_FUNCTION)(void);

class CourseManager {
public:
	static CourseBase* CreateCourse(std::string name);
	static void AddReflectionCourse(std::string name, CUSTOM_REFLECT_COURSE_FUNCTION ctr);
private:
	CourseManager() = default;
	virtual ~CourseManager();
	CourseBase* Create(std::string name);
	std::map<std::string, CUSTOM_REFLECT_COURSE_FUNCTION> AllCourse;
	static CourseManager* Instance();
};