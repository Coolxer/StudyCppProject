#include "LessonList.h"
#include "Lesson.h"

bool LessonList::showByName(std::string name)
{
	for (int i = 0; i < this->getNumberOfObjects(); i++)
	{
		Lesson* lesson = (Lesson*)this->getObjectByHardIndex(i);
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

	for (int i = 0; i < this->getNumberOfObjects(); i++)
	{
		Lesson* lesson = (Lesson*)this->getObjectByHardIndex(i);
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
