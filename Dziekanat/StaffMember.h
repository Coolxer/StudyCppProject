#pragma once
#include "Person.h"

class StaffMember :public Person
{
private:
	std::string academic_degrees;
	int cash;
	int numberOfLessonsProvided;

	/* 1 lesson
	lic/inz = 200, 
	mgr = 400, 
	dr = 700, 
	prof = 1000

	*/

	void calcCash();

public:
	StaffMember(std::string firstName, std::string lastName, int age, std::string academic_degrees);

	std::string getAcademicDegrees() const;
	int getCash() const;

	bool isProfessor() const;

	void increaseLessons();

	static void showHeader();
	void show(bool withHeader = false);
};

