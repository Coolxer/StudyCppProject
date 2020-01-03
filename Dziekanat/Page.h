#pragma once
#include "windows.h"

class Page
{
private:
	int index;
	HANDLE *console;
public:
	Page();
	Page(int index, HANDLE* console) { this->index = index ; this->console = console; }

	HANDLE* getConsole() { return this->console; }

	virtual void draw() = 0;
};

