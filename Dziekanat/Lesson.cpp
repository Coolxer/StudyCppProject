#include "Lesson.h"

Lesson::Lesson(std::string name, int startTime, int duration)
{
	this->name = name;
	this->startTime = startTime;
	this->duration = duration;
}

int Lesson::getStartTime()
{
	return this->startTime;
}

int Lesson::getDuration()
{
	return this->duration;
}
