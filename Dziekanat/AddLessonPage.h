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
	Lesson* lesson;

	std::string type;
	std::string name;
	int startTime;
	int duration;
	int maxPlaces;

	int currentStep;

	void resetValues();

	void testString(std::string text, std::string* pointer);
	void testNumber(std::string text, int* pointer, int min, int max);
public:
	AddLessonPage(Window* window, LessonsPage* lessonsPage);
	~AddLessonPage();

	void draw();
	void service();
};

