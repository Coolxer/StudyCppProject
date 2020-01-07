#include "Lesson.h"

Lesson::Lesson(std::string type, std::string name, int startTime, int duration, int maxPlaces)
{
	this->type = type;
	this->name = name;
	this->startTime = startTime;
	this->duration = duration;

	this->maxPlaces = this->freePlaces = maxPlaces;
}


int Lesson::getIndex() const
{
	return this->index;
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

int Lesson::getMaxPlaces() const
{
	return this->maxPlaces;
}

int Lesson::getFreePlaces() const
{
	return this->freePlaces;
}

void Lesson::setIndex(int index)
{
	this->index = index;
}

void Lesson::showHeader()
{
	std::cout << " ID " << " Typ " << " Nazwa " << " Godzina rozpoczecia " << " Czas trwania " << " zajete / max "<< std::endl;
}

void Lesson::show(bool withHeader)
{
	if (withHeader)
		this->showHeader();

	std::cout << "-----------------" << std::endl;
	std::cout << this->id << " | " << this->type << " | " << this->name << " | " << this->startTime << " | " << this->duration << " | " << this->maxPlaces - this->freePlaces << "/" << this->maxPlaces << std::endl;
}
