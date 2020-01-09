#pragma once
#include <vector>
#include <string>

#include "Student.h"
#include "StaffMember.h"
#include "Lesson.h"

class ObjectList
{
private:
	int index;
	std::vector <Object> objects;
public:
	ObjectList(int startIndex = 0);
	~ObjectList();

	int addObject(Object* o);
	int removeObject(int index);
	Object* getObjectByHardIndex(int index);
	Object* getObjectByIndex(int index);

	bool showAll();
	bool showByIndex(int index);

	int getNumberOfObjects();
};

