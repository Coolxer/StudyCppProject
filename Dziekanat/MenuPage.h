#pragma once
#include "Page.h"
#include "TextBox.h"
#include "Menu.h"

class MenuPage : public Page
{
private:
	TextBox titleBox;
	Menu menu;
	TextBox infoBox;

public:
	MenuPage(Window *window);

	void draw();
	void service();
};

