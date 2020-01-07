#include "Lesson.h"

Lesson::Lesson(std::string type, std::string name, int startTime, int duration)
{
	this->type = type;
	this->name = name;
	this->startTime = startTime;
	this->duration = duration;
}

void Lesson::setId(int id)
{
	this->id = id;
}

int Lesson::getId() const
{
	return this->id;
}

std::string Lesson::getType() const
{
	return this->type;
}

std::string Lesson::getName() const
{
	return this->name;
}

int Lesson::getStartTime() const
{
	return this->startTime;
}

int Lesson::getDuration() const
{
	return this->duration;
}

void Lesson::show(bool withHeader)
{
	if (withHeader)
		std::cout << " ID " << " Typ " << " Nazwa " << " Godzina rozpoczecia " << " Czas trwania " << std::endl;

	std::cout << "-----------------" << std::endl;
	std::cout << this->id << " | " << this->type << " | " << this->name << " | " << this->startTime << " | " << this->duration << std::endl;
}
