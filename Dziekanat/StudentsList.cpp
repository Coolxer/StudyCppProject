#include "StudentsList.h"

#include <iostream>

StudentsList::StudentsList()
{
	this->startIndex = 16000;

	//this->addStudent(Student("lukasz", "milos", 21, this->startIndex + 1));
}

void StudentsList::addStudent(Student &s)
{
	this->students.push_back(s);
}

void StudentsList::removeStudent()
{

}

void StudentsList::showAllStudents()
{
	for (int i = 0; i < (int)this->students.size(); i++)
		this->students[i].show();
}

void StudentsList::showStudentbyIndex(int index)
{
	for (int i = 0; i < (int)this->students.size(); i++)
	{
		if (this->students[i].getIndex() == index)
			this->students[i].show();
	}
}

