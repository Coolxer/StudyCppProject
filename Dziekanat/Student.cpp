#include "Student.h"

#include <iostream>

Student::Student(std::string firstName, std::string lastName, int age, std::string field, int level, int year, std::string type) : Person(firstName, lastName, age)
{
	this->study = Study(field, level, year, type);
}

Student::Student(const Student& model)
{
	this->index = model.index;
	this->study = model.study;
}

Student& Student::operator = (const Student& model)
{
	this->index = model.index;
	this->study = model.study;

	return *this;
}

Student::~Student()
{

}

bool Student::operator ==(const Student& s)
{
	/* jesli wszystkie pola Studenta A i Studenta B sa takie same, to obiekty sa sobie rowne */
	if ((this->index == s.index) && (this->getFirstName() == s.getFirstName()) && (this->getLastName() == s.getLastName()) && (this->getAge() == s.getAge()) && (this->study.getField() == s.study.getField()) && (this->study.getLevel() == s.study.getLevel()) && (this->study.getYear() == s.study.getYear()) && (this->study.getType() == s.study.getType()))
		return true;
	return false;
}

Study* Student::getStudy()
{
	return &this->study;
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
	if (withHeader) // parametr withHeader jest opcjonalny
		this->showHeader();

	std::cout << "-----------------" << std::endl;
	std::cout << this->getFirstName() << " | " << this->getLastName() << " | " << this->getAge() << " | " << this->getIndex() << " | ";
	std::cout << this->study.getField() << " | " << this->study.getLevel() << " | " << this->study.getYear() << " | " << this->study.getType() << std::endl;
}
