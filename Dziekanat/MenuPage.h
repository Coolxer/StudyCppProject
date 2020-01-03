#pragma once
#include "Page.h"

#include "TextBox.h"
#include "Menu.h"
#include "TextBox.h"

class MenuPage :public Page
{
private:
	TextBox tileBox;
	Menu menu;
	TextBox infoBox;

public:
	MenuPage();
	MenuPage(int index, HANDLE *console);

	void draw();
};

