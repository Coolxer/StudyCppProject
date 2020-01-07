#pragma once
#include <vector>
#include <string>

#include "Lesson.h"

class LessonsList
{
private:
	int index;
	std::vector <Lesson> lessons;
public:
	LessonsList();
	~LessonsList();

	int addLesson(Lesson* s);
	int removeLesson(int index);
	bool showLessons();
	bool showLessonById(int index);

	bool showSpecificLessons(std::string type);

	int getNumberofLessons();
};

