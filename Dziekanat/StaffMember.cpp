#include "StaffMember.h"

#include <iostream>

StaffMember::StaffMember(std::string firstName, std::string lastName, int age, std::string academic_degree) : Person(firstName, lastName, age)
{
	this->academic_degree = academic_degree;
	this->cash = 0;
	this->numberOfLessonsProvided = 0;
}

StaffMember::StaffMember(const StaffMember& model)
{
	this->academic_degree = model.academic_degree;
	this->cash = model.cash;
	this->numberOfLessonsProvided = model.numberOfLessonsProvided;
}

StaffMember& StaffMember::operator = (const StaffMember& model)
{
	this->academic_degree = model.academic_degree;
	this->cash = model.cash;
	this->numberOfLessonsProvided = model.numberOfLessonsProvided;

	return *this;
}

bool StaffMember::isEqual(Object* model)
{
	StaffMember* staffMember = (StaffMember*)model;

	if(this->getFirstName() == staffMember->getFirstName() && this->getLastName() == staffMember->getLastName() && this->getAge() == staffMember->getAge() && this->academic_degree == staffMember->academic_degree)
		return true;

	return false;
}

StaffMember::~StaffMember()
{

}

std::string StaffMember::getAcademicDegree() const
{
	return this->academic_degree;
}

int StaffMember::getCash() const
{
	return this->cash;
}

void StaffMember::calcCash()
{
	int converter; // przelicznik ( mnoznik )

	/* ustawienie przelicznika na podstawie posidanych stopni naukowych */

	if (this->academic_degree == "lic." || this->academic_degree == "inz.")
		converter = 200;
	else if (this->academic_degree == "mgr" )
		converter = 400;
	else if (this->academic_degree == "dr")
		converter = 700;
	else if (this->academic_degree == "prof.")
		converter = 1000;
	else
		converter = 0;

	this->cash = converter * this->numberOfLessonsProvided; // obliczenie wynagrodzenia na podstawie posiadanych stopni naukowych i ilosci prowadzonych zajec
}

bool StaffMember::isProfessor() const
{
	if (this->academic_degree == "prof.") // sprawdzenie czy pracownik ma tytul profesora, jesli tak to zwraca true
		return true;

	return false; // jesli pracownik nie jest profesorem, to zwraca false
}

void StaffMember::increaseLessons()
{
	this->numberOfLessonsProvided++; // zwiekszenie licznika prowadzonych zajec przez pracownika
	this->calcCash(); // obliczenie wynagrodzenia
}

void StaffMember::decreaseLessons()
{
	if (this->numberOfLessonsProvided > 0)
	{
		this->numberOfLessonsProvided--; // zmniejszenie licznika prowadzonych zajec przez pracownika
		this->calcCash(); // obliczenie wynagrodzenia
	}
}

void StaffMember::showHeader()
{
	std::cout << std::endl << " ID | " << "Imie | " << "Nazwisko | " << "Wiek | " << "Tytuly | " << "Wynagrodzenie | " << "Liczba zajec |" << std::endl;
}

void StaffMember::show(bool withHeader)
{
	if (withHeader) // parametr withHeader jest opcjonalny
		this->showHeader();

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
	std::cout << " " << this->getIndex() << " | " << this->getFirstName() << " | " << this->getLastName() << " | " << this->getAge() << " | ";
	std::cout << this->academic_degree << " | " << this->cash << " | " << this->numberOfLessonsProvided << std::endl;
}