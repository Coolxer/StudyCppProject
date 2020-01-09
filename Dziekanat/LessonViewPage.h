#pragma once
#include <string>
#include "Page.h"
#include "TextBox.h"

#include "LessonsPage.h"

class LessonsViewPage : public Page
{
private:
	TextBox header;
	TextBox info;

	LessonsList* lessonsList;

public:
	LessonsViewPage(Window* window, LessonsPage* lessonsPage);

	void draw();
	void service();
};

