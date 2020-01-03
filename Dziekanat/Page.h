#pragma once
#include "windows.h"

class Page
{
private:
	HANDLE console;

public:
	Page(HANDLE console) { this->console = console; }

	HANDLE getConsole() { return this->console; }

	virtual void draw() = 0;
};

