#pragma once
#include "Page.h"
#include "TextBox.h"
#include "Menu.h"

class MenuPage : public Page
{
private:
	TextBox header;
	Menu menu;
	TextBox info;

public:
	MenuPage(Window *window);

	void draw();
	void service();
};

