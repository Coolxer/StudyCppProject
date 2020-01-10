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
protected:
	std::vector <Object*> objects;
public:
	ObjectList();
	~ObjectList();

	void setStartIndex(int startIndex);

	int addObject(Object* o);
	int removeObject(int index);
	Object* getObjectByIndex(int index);

	bool showAll();
	bool showByIndex(int index);

	int getNumberOfObjects();
};

