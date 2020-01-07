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
	Lesson* getLessonByName(std::string name);

	bool showLessons();
	bool showLessonById(int index);
	bool showLessonByName(std::string name);
	bool showSpecificLessons(std::string type);

	int getNumberOfLessons();
};

