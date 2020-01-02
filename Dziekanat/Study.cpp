#include "Study.h"

Study::Study(std::string field, std::string year, std::string type)
{
	this->field = field;
	this->year = year;
	this->type = type;
}

std::string Study::getField() const
{
	return this->field;
}

std::string Study::getYear() const
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

void Study::setYear(std::string year)
{
	this->year = year;
}

void Study::setType(std::string type)
{
	this->type = type;
}
