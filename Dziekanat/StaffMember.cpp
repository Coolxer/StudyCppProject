#include "StaffMember.h"

StaffMember::StaffMember(std::string firstName, std::string lastName, int age, std::string academic_degree, int cash) : Person(firstName, lastName, age)
{
	this->academic_degree = academic_degree;
	this->cash = cash;
}

std::string StaffMember::getAcademicDegree()
{
	return this->academic_degree;
}

int StaffMember::getCash()
{
	return this->cash;
}
