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
	ObjectList();
	~ObjectList();

	int addObject(Object* o);
	int removeObject(int index);
	Object* getObjectByIndex(int index);

	void setStartIndex(int index);

	bool showAll();

	int getNumberOfObjects();
};

