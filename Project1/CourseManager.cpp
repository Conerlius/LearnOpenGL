#include "CourseManager.h"
#include <iostream>

// 还没有释放
static CourseManager* _instance;

CourseBase* CourseManager::CreateCourse(std::string name)
{
	return Instance()->Create(name);
}

void CourseManager::AddReflectionCourse(std::string name, CUSTOM_REFLECT_COURSE_FUNCTION ctr)
{
	Instance()->AllCourse.insert(std::pair<std::string, CUSTOM_REFLECT_COURSE_FUNCTION>(name, ctr));
}

CourseManager::~CourseManager()
{
	AllCourse.clear();
}

CourseBase* CourseManager::Create(std::string name)
{
	auto course = AllCourse.find(name);
	if(course != AllCourse.end())
		return course->second();
	return nullptr;
}

CourseManager* CourseManager::Instance()
{
	if (_instance == nullptr) {
		_instance = new CourseManager();
	}
	return _instance;
}
