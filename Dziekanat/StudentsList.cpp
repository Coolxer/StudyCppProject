#include "StudentsList.h"

#include <iostream>

StudentsList::StudentsList()
{
	this->startIndex = 16000;
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
	std::cout << "#################################" << std::endl;
	for (int i = 0; i < this->students.size(); i++)
	{
		this->students[i].show();
	}
}

void StudentsList::showStudentbyIndex(int index)
{

	for (int i = 0; i < this->students.size(); i++)
	{
		if (this->students[i].getIndex() == index)
			this->students[i].show();
	}
}

