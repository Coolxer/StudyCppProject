#pragma once
#include "windows.h"
#include "Window.h"

#include <iostream>
#include "CmdManager.h"

class Page
{
private:
	Window* window;
public:
	Page(Window* window);

	Window* getWindow();

	virtual void draw() = 0;
	virtual void service() = 0;
};

