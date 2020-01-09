#pragma once
#include "ObjectList.h"

class StudentList: public ObjectList
{
public:
	StudentList();

	bool showByField(std::string field);
	bool showByType(std::string type);
};

