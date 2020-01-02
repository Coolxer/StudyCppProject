#pragma once
#include "Person.h"

class Student :public Person
{
private:
	int index;
	std::string pesel;

public:
	Student(std::string firstName, std::string lastName, std::string pesel, int age, int index);

	int getIndex();
	std::string getPesel();
};

