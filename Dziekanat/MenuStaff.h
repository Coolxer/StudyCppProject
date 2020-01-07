#pragma once
#include "MenuElement.h"

#define COUNT 6

class MenuStaff
{
private:
	MenuElement menuElements[COUNT];
public:
	MenuStaff();
	void show();
};
