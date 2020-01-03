#pragma once
#include "Person.h"
#include "Study.h"

class Student :public Person
{
private:
	int index;
	Study study;

public:
	Student(std::string firstName, std::string lastName, int age, int index);
	void setStudy(std::string field, std::string year, std::string type);

	int getIndex();

	void changeStudyYear(std::string year);
	void changeStudyType(std::string type);

	void show();
};

