#include "StaffMember.h"

#include <iostream>

StaffMember::StaffMember(std::string firstName, std::string lastName, int age, std::string academic_degrees) : Person(firstName, lastName, age)
{
	this->academic_degrees = academic_degrees;
	this->numberofLessonsProvided = 0;
}

int StaffMember::getIndex() const
{
	return this->index;
}


std::string StaffMember::getAcademicDegrees() const
{
	return this->academic_degrees;
}

int StaffMember::getCash() const
{
	return this->cash;
}

bool StaffMember::isProfessor() const
{
	if (this->academic_degrees.find("prof") != std::string::npos)
		return true;

	return false;
}

void StaffMember::setIndex(int index)
{
	this->index = index;
}

void StaffMember::showHeader()
{
	std::cout << " ID " << " Imie " << " Nazwisko " << " Wiek " << " Tytuly " << " Wynagrodzenie " << " Liczba zajec " << std::endl;
}


void StaffMember::show(bool withHeader)
{
	if (withHeader)
		this->showHeader();

	std::cout << "-----------------" << std::endl;
	std::cout << this->index << " | " << this->getFirstName() << " | " << this->getLastName() << " | " << this->getAge() << " | ";
	std::cout << this->academic_degrees << " | " << this->cash << " | " << this->numberofLessonsProvided << std::endl;
}