#pragma once
#include "Person.h"

class StaffMember :public Person
{
private:
	int id;
	std::string academic_degrees;
	int cash;

	int numberofLessonsProvided;

public:
	StaffMember(std::string firstName, std::string lastName, int age, std::string academic_degrees);

	void setId(int id);
	int getId() const ;

	std::string getAcademicDegrees() const;
	int getCash();

	bool isProfessor();

	void show(bool withHeader = false);
	
};

