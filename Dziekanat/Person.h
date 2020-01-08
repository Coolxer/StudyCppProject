#pragma once
#include <string>

#include "Object.h"

class Person: public Object
{
private:
	std::string firstName;
	std::string lastName;
	int age;
public:
	Person(){}
	Person(std::string firstName, std::string lastName, int age);

	std::string getFirstName() const;
	std::string getLastName() const;
	int getAge() const;
};

