#pragma once
#include "MainPage.h"
#include "LessonList.h"

class LessonPage : public MainPage
{
private:
	Menu menu;
	LessonList lessonList;
public:
	LessonPage(Window* window, std::string headerText);
	~LessonPage();

	void service();
};

