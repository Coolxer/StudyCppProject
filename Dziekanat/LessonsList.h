#pragma once
#include <vector>
#include <string>

#include "Lesson.h"

class LessonsList
{
private:
	int id;
	std::vector <Lesson> lessons;
public:
	LessonsList();
	~LessonsList();

	int addLesson(Lesson* s);
	int removeLesson(int id);
	bool showLessons();
	bool showLessonById(int id);

	bool showSpecificLessons(std::string type);

	int getNumberofLessons();
};

