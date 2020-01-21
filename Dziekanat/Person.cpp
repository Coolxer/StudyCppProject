#include "Person.h"

Person::Person(std::string firstName, std::string lastName, int age)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
}

Person::Person(const Person& model)
{
	this->firstName = model.firstName;
	this->lastName = model.lastName;
	this->age = model.age;
}

Person& Person::operator = (const Person& model)
{
	this->firstName = model.firstName;
	this->lastName = model.lastName;
	this->age = model.age;

	return *this;
}

bool Person::operator ==(const Object& model)
{
	Person* person = (Person*)&model;

	if (this->firstName == person->firstName && this->lastName == person->lastName && this->age == person->age)
		return true;

	return false;
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
