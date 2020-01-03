#pragma once
#include "windows.h"

#include "Menu.h"
#include "TextBox.h"

#include "Page.h"
#include "MenuPage.h"

class Window
{
private:
	HANDLE console;
	Page* pages[1];

	void clear();
public:
	Window();
	~Window();

	void drawPage(int pageIndex);
};

