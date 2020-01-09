#pragma once
#include "MainPage.h"
#include "ObjectList.h"

class StaffPage : public MainPage
{
private:
	Menu menu;
public:
	StaffPage(Window* window, std::string headerText);

	void service();
};

