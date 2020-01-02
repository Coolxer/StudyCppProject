#pragma once
#include "Person.h"

class StaffMember :public Person
{
private:
	std::string academic_degree;
	int cash;

public:
	StaffMember(std::string firstName, std::string lastName, int age, std::string academic_degree, int cash);

	std::string getAcademicDegree();
	int getCash();
};

