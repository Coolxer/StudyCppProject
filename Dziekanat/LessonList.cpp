#include "LessonList.h"
#include "Lesson.h"

Lesson* LessonList::getByName(std::string name)
{
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Lesson* lesson = (Lesson*)&this->objects[i];
		if (lesson->getName() == name)
			return lesson;
	}

	return nullptr;
}

bool LessonList::showByName(std::string name)
{
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Lesson* lesson = (Lesson*)&this->objects[i];
		if (lesson->getName() == name)
		{
			lesson->show(true);
			return true;
		}
	}
	return false;
}

bool LessonList::showSpecificType(std::string type)
{
	int count = 0;

	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Lesson* lesson = (Lesson*)&this->objects[i];
		if (lesson->getType() == type)
		{
			lesson->show();
			count++;
		}
	}

	if (count > 0)
		return true;

	return false;
}
