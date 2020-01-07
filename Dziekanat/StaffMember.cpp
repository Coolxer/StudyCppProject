#include "StaffMember.h"

#include <iostream>

StaffMember::StaffMember(std::string firstName, std::string lastName, int age, std::string academic_degrees) : Person(firstName, lastName, age)
{
	this->academic_degrees = academic_degrees;
	this->numberofLessonsProvided = 0;
}

void StaffMember::setId(int id)
{
	this->id = id;
}

int StaffMember::getId() const
{
	return this->id;
}

std::string StaffMember::getAcademicDegrees() const
{
	return this->academic_degrees;
}

int StaffMember::getCash()
{
	return this->cash;
}

bool StaffMember::isProfessor()
{
	if (this->academic_degrees.find("prof") != std::string::npos)
		return true;

	return false;
}

void StaffMember::show(bool withHeader)
{
	if (withHeader)
		std::cout << " ID " << " Imie " << " Nazwisko " << " Wiek " << " Tytuly " << " Wynagrodzenie " << " Liczba zajec " << std::endl;

	std::cout << "-----------------" << std::endl;
	std::cout << this->id << " | " << this->getFirstName() << " | " << this->getLastName() << " | " << this->getAge() << " | ";
	std::cout << this->academic_degrees << " | " << this->cash << " | " << this->numberofLessonsProvided << std::endl;
}