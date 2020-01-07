#include "LessonsList.h"

#include <iostream>

LessonsList::LessonsList()
{
	this->index = 1;

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

	this->index++;
	this->lessons.back().setIndex(this->index);

	return this->index;
}

int LessonsList::removeLesson(int index)
{
	for (int i = 0; i < (int)this->lessons.size(); i++)
	{
		if (this->lessons[i].getIndex() == index)
		{
			this->lessons.erase(this->lessons.begin() + i);
			return index;
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

bool LessonsList::showLessonById(int index)
{
	for (int i = 0; i < (int)this->lessons.size(); i++)
	{
		if (this->lessons[i].getIndex() == index)
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

