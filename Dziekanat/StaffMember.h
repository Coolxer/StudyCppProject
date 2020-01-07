#pragma once
#include "Person.h"

class StaffMember :public Person
{
private:
	int index;

	std::string academic_degrees;
	int cash;

	int numberofLessonsProvided;

public:
	StaffMember(std::string firstName, std::string lastName, int age, std::string academic_degrees);

	int getIndex() const ;

	std::string getAcademicDegrees() const;
	int getCash() const;

	bool isProfessor() const;

	void setIndex(int id);

	static void showHeader();
	void show(bool withHeader = false);
	
};

