#include "Student.h"

#include <iostream>

Student::Student(std::string firstName, std::string lastName, int age, std::string field, int level, int year, std::string type) : Person(firstName, lastName, age)
{
	this->study = Study(field, level, year, type);
}

int Student::getIndex()
{
	return this->index;
}
Study* Student::getStudy()
{
	return &this->study;
}


void Student::setIndex(int index)
{
	this->index = index;
}

void Student::changeStudyYear(int year)
{
	this->study.setYear(year);
}

void Student::changeStudyType(std::string type)
{
	this->study.setType(type);
}

void Student::showHeader()
{
	std::cout << " Imie " << " Nazwisko " << " Wiek " << " Indeks " << " Kierunek " << " Stopien " << " Rok " << " Typ " << std::endl;
}

void Student::show(bool withHeader)
{
	if (withHeader)
		this->showHeader();

	std::cout << "-----------------" << std::endl;
	std::cout << this->getFirstName() << " | " << this->getLastName() << " | " << this->getAge() << " | " << this->index << " | ";
	std::cout << this->study.getField() << " | " << this->study.getLevel() << " | " << this->study.getYear() << " | " << this->study.getType() << std::endl;
}
