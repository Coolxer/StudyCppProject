#include "Student.h"

#include <iostream>

Student::Student(std::string firstName, std::string lastName, int age, std::string department, std::string field, int level, int year, std::string type)
																							  : Person(firstName, lastName, age)
																							   , study(department, field, level, year, type)
{
	this->index = 0;
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

bool Student::isEqual(Object* model)
{
	Student* student = (Student*)model;

	if ((this->getFirstName() == student->getFirstName()) && (this->getLastName() == student->getLastName()) && (this->getAge() == student->getAge()) && (this->study.getField() == student->study.getField()) && (this->study.getLevel() == student->study.getLevel()) && (this->study.getYear() == student->study.getYear()) && (this->study.getType() == student->study.getType()))
		return true;

	return false;
}

Study* Student::getStudy()
{
	return &this->study;
}

void Student::showHeader()
{
	std::cout << std::endl << " Imie " << " Nazwisko " << " Wiek " << " Indeks " << " Wydzial " << " Kierunek " << " Stopien " << " Rok " << " Typ " << std::endl;
}

void Student::show(bool withHeader)
{
	if (withHeader) // parametr withHeader jest opcjonalny
		this->showHeader();

	std::cout << "-----------------" << std::endl;
	std::cout << this->getFirstName() << " | " << this->getLastName() << " | " << this->getAge() << " | " << this->getIndex() << " | ";
	std::cout << this->study.getDepartment() << " | " << this->study.getField() << " | " << this->study.getLevel() << " | " << this->study.getYear() << " | " << this->study.getType() << std::endl;
}
