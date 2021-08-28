#pragma once

#include "CourseManager.h"

#define SafeDelete(p) if(p){delete p;p=nullptr;}

#define COURSE_CLASS(NAME) static CourseBase* Core_reflect_Create_##NAME(){ \
return new NAME();} \
CUSTOM_REFLECT_ACTION Core_reflect_##NAME(#NAME, &Core_reflect_Create_##NAME);

#define GENERATE_COURSE(NAME) 