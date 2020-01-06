#pragma once
#include "MenuElement.h"

#define COUNT 3

class Menu
{
private:
	MenuElement menuElements[COUNT];

public:
	Menu();
	void show();
};

