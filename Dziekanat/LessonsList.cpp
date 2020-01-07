#include "LessonsList.h"

#include <iostream>

LessonsList::LessonsList()
{
	this->id = 1;

	this->addLesson(new Lesson("projekt", "programowanie", 5, 90, 30));
	this->addLesson(new Lesson("laboratorium", "systemy", 10, 120, 15));
}

LessonsList::~LessonsList()
{
	this->lessons.clear();
}

int LessonsList::addLesson(Lesson* lesson)
{
	this->lessons.push_back(*lesson);

	this->id++;
	this->lessons.back().setId(this->id);

	return this->id;
}

int LessonsList::removeLesson(int id)
{
	for (int i = 0; i < (int)this->lessons.size(); i++)
	{
		if (this->lessons[i].getId() == id)
		{
			this->lessons.erase(this->lessons.begin() + i);
			return id;
		}
	}
	return 0;
}

bool LessonsList::showLessons()
{
	for (int i = 0; i < (int)this->lessons.size(); i++)
		this->lessons[i].show();

	if (this->lessons.size() != 0)
		return true;

	return false;
}

bool LessonsList::showLessonById(int id)
{
	for (int i = 0; i < (int)this->lessons.size(); i++)
	{
		if (this->lessons[i].getId() == id)
		{
			this->lessons[i].show(true);
			return true;
		}
	}
	return false;
}

bool LessonsList::showSpecificLessons(std::string type)
{
	int count = 0;
	for (int i = 0; i < (int)this->lessons.size(); i++)
	{
		if (this->lessons[i].getType() == type)
		{
			this->lessons[i].show();
			count++;
		}
	}

	if (count > 0)
		return true;

	return false;
}

int LessonsList::getNumberofLessons()
{
	return (int)this->lessons.size();
}

