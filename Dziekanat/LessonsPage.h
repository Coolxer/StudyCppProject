#pragma once
#include "MainPage.h"
#include "ObjectList.h"

class LessonsPage : public MainPage
{
private:
	Menu menu;
public:
	LessonsPage(Window* window, std::string headerText);

	void service();
};

