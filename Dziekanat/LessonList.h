#pragma once
#include "ObjectList.h"

class LessonList : public ObjectList
{
public:
	LessonList() {}

	bool showByName(std::string name);
	bool showSpecificType(std::string type);
};

