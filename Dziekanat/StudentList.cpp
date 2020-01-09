#include "StudentList.h"

#include "Student.h"

StudentList::StudentList()
{
	this->setStartIndex(16000);

	this->addObject(new Student("Lukasz", "Milos", 21, "inf", 1, 2, "zaoczne"));
	this->addObject(new Student("Rafal", "Magrys", 22, "inf", 1, 2, "stacjonarne"));
	this->addObject(new Student("Kuba", "Stanislawczyk", 21, "bud", 1, 2, "zaoczne"));
	this->addObject(new Student("Damian", "Pietraszek", 27, "inf", 1, 2, "zaoczne"));
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