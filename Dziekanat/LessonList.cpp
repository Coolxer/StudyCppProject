#include "LessonList.h"

LessonList::LessonList()
{
	this->addObject(new Lesson("projekt", "programowanie", 5, 90, 30));
	this->addObject(new Lesson("laboratorium", "systemy", 10, 120, 15));
}

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

bool LessonList::lessonExist(std::string name, std::string type)
{
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Lesson* lesson = (Lesson*)&this->objects[i];

		if (lesson->getName() == name && lesson->getType() == type)
			return true;
	}

	return false;
}

void LessonList::removeStaffMemberFromLessons(StaffMember* staffMember)
{
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Lesson* lesson = (Lesson*)&this->objects[i];
		if (lesson->getStaffMember() == staffMember)
			lesson->removeStaffMember();
	}
}

void LessonList::removeStudentFromLessons(Student* student)
{
	int x;

	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Lesson* lesson = (Lesson*)&this->objects[i];
		x = lesson->consistsStudent(student);

		if (x != -1)
			lesson->removeStudent(student, x);
	}
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
