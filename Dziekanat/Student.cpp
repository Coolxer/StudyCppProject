#include "Student.h"

Student::Student(std::string firstName, std::string lastName, int age, int index) : Person(firstName, lastName, age)
{
	this->index = index;
}

void Student::setStudy(std::string field, std::string year, std::string type)
{
	this->study = Study(field, year, type);
}

int Student::getIndex()
{
	return this->index;
}

void Student::changeStudyYear(std::string year)
{
	this->study.setYear(year);
}

void Student::changeStudyType(std::string type)
{
	this->study.setType(type);
}
