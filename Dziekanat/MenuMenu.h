#pragma once
#include "MenuElement.h"

#define COUNT 3

class MenuMenu
{
private:
	MenuElement menuElements[COUNT];
public:
	MenuMenu();
	void show();
};

