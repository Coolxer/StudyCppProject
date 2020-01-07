#pragma once
#include "Person.h"
#include "Study.h"

class Student :public Person
{
private:
	int index;
	Study study;

public:
	Student(std::string firstName, std::string lastName, int age, std::string field, int level, int year, std::string type);

	int getIndex();
	void setIndex(int index);

	void changeStudyYear(int year);
	void changeStudyType(std::string type);

	void show(bool withHeader=false);

	Study* getStudy();
};

