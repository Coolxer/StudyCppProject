#pragma once
#include "Page.h"

#include "MenuElement.h"
#include "TextBox.h"
#include "LessonsList.h"

class LessonsPage : public Page
{
private:
	TextBox header;
	MenuElement menuElements[6];
	TextBox info;

	LessonsList lessonsList;
public:
	LessonsPage(Window* window);

	LessonsList* getStaffList();

	void draw();
	void service();
};

