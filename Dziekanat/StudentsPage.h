#pragma once
#include "MainPage.h"
#include "ObjectList.h"

class StudentsPage : public MainPage
{
private:
	Menu menu;
public:
	StudentsPage(Window* window, std::string headerText);

	void service();
};

