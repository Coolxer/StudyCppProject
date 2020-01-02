#include "Student.h"

Student::Student(std::string firstName, std::string lastName, std::string pesel, int age, int index) : Person(firstName, lastName, age)
{
	this->pesel = pesel;
	this->index = index;
}

int Student::getIndex()
{
	return this->index;
}

std::string Student::getPesel()
{
	return this->pesel;
}
