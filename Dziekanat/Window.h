#pragma once
#include "windows.h"

class Page;

class Window
{
private:
	HANDLE console;
	Page* pages[10];

	int activePageIndex;

	void clear();
	void drawActivePage();
public:
	Window();
	~Window();

	void refresh();

	void setActivePage(int pageIndex);
	HANDLE getConsole();
};

