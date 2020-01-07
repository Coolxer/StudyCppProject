#pragma once
#include "Page.h"
#include "TextBox.h"
#include "MenuMenu.h"

class MenuPage : public Page
{
private:
	TextBox header;
	MenuMenu menu;
	TextBox info;

public:
	MenuPage(Window *window);

	void draw();
	void service();
};

