#include "StudentList.h"

#include "Student.h"

StudentList::StudentList()
{

}

bool StudentList::showByField(std::string field)
{
	int count = 0;
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Student* student = (Student*)&this->objects[i];
		if (student->getStudy()->getField()== field)
		{
			student->show();
			count++;
		}
	}
	if (count > 0)
		return true;

	return false;
}

bool StudentList::showByType(std::string type)
{
	int count = 0;
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Student* student = (Student*)&this->objects[i];
		if (student->getStudy()->getType() == type)
		{
			student->show();
			count++;
		}
	}
	if (count > 0)
		return true;

	return false;
}