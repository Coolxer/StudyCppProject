#include "Study.h"

#include <iostream>
#include <windows.h>

Study::Study(std::string department, std::string field, int level, int year, std::string type)
{
	this->department = department;
	this->field = field;
	this->level = level;
	this->year = year;
	this->type = type;
}

Study::Study(const Study& model)
{
	this->department = model.department;
	this->field = model.field;
	this->level = model.level;
	this->year = model.year;
	this->type = model.type;
}

Study& Study::operator = (const Study& model)
{
	this->department = model.department;
	this->field = model.field;
	this->level = model.level;
	this->year = model.year;
	this->type = model.type;

	return *this;
}

Study::~Study()
{

}

std::string Study::getDepartment() const
{
	return this->department;
}

std::string Study::getField() const
{
	return this->field;
}

int Study::getLevel() const
{
	return this->level;
}

int Study::getYear() const
{
	return this->year;
}

std::string Study::getType() const
{
	return this->type;
}

void Study::setDepartment(std::string department)
{
	this->department = department;
}

void Study::setField(std::string field)
{
	this->field = field;
}

void Study::setLevel(int level)
{
	this->level = level;
}

void Study::setYear(int year)
{
	this->year = year;
}

void Study::setType(std::string type)
{
	this->type = type;
}
