#include "StudentsList.h"

#include <iostream>

StudentsList::StudentsList()
{
	this->startIndex = 16000;

	this->addStudent(new Student("Lukasz", "Milos", 21, "inf", 1, 2, "zaoczne"));
	this->addStudent(new Student("Rafal", "Magrys", 22, "inf", 1, 2, "stacjonarne"));
	this->addStudent(new Student("Kuba", "Stanislawczyk", 21, "bud", 1, 2, "zaoczne"));
	this->addStudent(new Student("Damian", "Pietraszek", 27, "inf", 1, 2, "zaoczne"));
}

StudentsList::~StudentsList()
{
	this->students.clear();
}

int StudentsList::addStudent(Student *s)
{
	this->students.push_back(*s);
	
	this->startIndex++;
	this->students.back().setIndex(this->startIndex);

	return this->startIndex;
}

int StudentsList::removeStudent(int index)
{
	for (int i = 0; i < (int)this->students.size(); i++)
	{
		if (this->students[i].getIndex() == index)
		{
			this->students.erase(this->students.begin() + i);
			return index;
		}
	}

	return 0;
}

bool StudentsList::showAllStudents()
{
	for (int i = 0; i < (int)this->students.size(); i++)
		this->students[i].show();

	if (this->students.size() != 0)
		return true;

	return false;
}

bool StudentsList::showStudentbyIndex(int index)
{
	for (int i = 0; i < (int)this->students.size(); i++)
	{
		if (this->students[i].getIndex() == index)
		{
			this->students[i].show(true);
			return true;
		}
	}
	return false;
}


bool StudentsList::showStudentsByField(std::string field)
{
	int count = 0;
	for (int i = 0; i < (int)this->students.size(); i++)
	{
		if (this->students[i].getStudy()->getField() == field)
		{
			this->students[i].show();
			count++;
		}
	}
	if (count > 0)
		return true;

	return false;
}

bool StudentsList::showStudentsByType(std::string type)
{
	int count = 0;
	for (int i = 0; i < (int)this->students.size(); i++)
	{
		if (this->students[i].getStudy()->getType() == type)
		{
			this->students[i].show();
			count++;
		}
	}
	if (count > 0)
		return true;

	return false;
}

int StudentsList::getNumberOfStudents()
{
	return (int)this->students.size();
}

