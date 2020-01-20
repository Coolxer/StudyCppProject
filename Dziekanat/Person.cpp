#include "Person.h"

Person::Person()
{

}

Person::Person(std::string firstName, std::string lastName, int age)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
}

Person::~Person()
{

}

std::string Person::getFirstName() const
{
	return this->firstName;
}

std::string Person::getLastName() const
{
	return this->lastName;
}

int Person::getAge() const
{
	return this->age;
}
