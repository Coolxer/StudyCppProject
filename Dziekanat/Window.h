#pragma once
#include "windows.h"

class Page;

class Window
{
private:
	HANDLE console;
	Page* pages[2];

	int activePageIndex;

	void clear();
	void drawActivePage();
public:
	Window();
	~Window();

	void setActivePage(int pageIndex);
	HANDLE getConsole();
};

