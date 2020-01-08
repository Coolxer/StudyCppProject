#include "Student.h"

#include <iostream>

Student::Student(std::string firstName, std::string lastName, int age, std::string field, int level, int year, std::string type) : Person(firstName, lastName, age)
{
	this->study = Study(field, level, year, type);
}

bool Student::operator ==(const Student& s)
{
	if ((this->index == s.index) && (this->getFirstName() == s.getFirstName()) && (this->getLastName() == s.getLastName()) && (this->getAge() == s.getAge()) && (this->study.getField() == s.study.getField()) && (this->study.getLevel() == s.study.getLevel()) && (this->study.getYear() == s.study.getYear()) && (this->study.getType() == s.study.getType()))
		return true;
	return false;
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
