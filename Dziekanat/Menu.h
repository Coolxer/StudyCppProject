#pragma once
#include "MenuElement.h"

#define COUNT 5

class Menu
{
private:
	MenuElement menuElements[COUNT];

public:
	Menu();
	void show();
};

