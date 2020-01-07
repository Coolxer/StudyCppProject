#pragma once
#include "Page.h"
#include "TextBox.h"
#include "MenuLesson.h"
#include "LessonsList.h"

class LessonsPage : public Page
{
private:
	TextBox header;
	MenuLesson menuLesson;
	TextBox info;

	LessonsList lessonsList;
public:
	LessonsPage(Window* window);

	LessonsList* getLessonsList();

	void draw();
	void service();
};

