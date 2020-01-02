#pragma once
#include "windows.h"

#include "Menu.h"
#include "TextBox.h"

class Window
{
private:
	TextBox tileBox;
	Menu menu;
	TextBox infoBox;

	HANDLE console;

	void clear();
public:
	Window();

	void refresh();
};

