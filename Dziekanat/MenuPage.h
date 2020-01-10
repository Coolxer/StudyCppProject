#pragma once
#include "MainPage.h"

class MenuPage : public MainPage
{
private:
	Menu menu;

public:
	MenuPage(Window* window);
	~MenuPage();

	void service();
};

