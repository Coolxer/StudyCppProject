#include "Study.h"

#include <iostream>
#include <windows.h>

Study::Study(std::string field, int level, int year, std::string type)
{
	this->field = field;
	this->level = level;
	this->year = year;
	this->type = type;
}

Study::~Study()
{

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
