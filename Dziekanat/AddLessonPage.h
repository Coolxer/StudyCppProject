#pragma once
#include <string>
#include "Page.h"
#include "TextBox.h"

#include "LessonsPage.h"

class AddLessonPage: public Page
{
private:
	TextBox header;
	TextBox info;

	LessonsList* lessonsList;

	std::string type;
	std::string name;
	int startTime;
	int duration;

	int currentStep;
	int maxPlaces;

	Lesson* lesson;

	void resetValues();

public:
	AddLessonPage(Window* window, LessonsPage* lessonsPage);
	~AddLessonPage();

	void draw();
	void service();
};

