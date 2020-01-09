#pragma once
#include "ObjectList.h"

class LessonList : public ObjectList
{
public:
	LessonList() {}

	Lesson* getByName(std::string name);

	bool showByName(std::string name);
	bool showSpecificType(std::string type);
};

