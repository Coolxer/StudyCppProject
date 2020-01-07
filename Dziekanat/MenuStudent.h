#pragma once
#include "MenuElement.h"

#define COUNT 8

class MenuStudent
{
private:
	MenuElement menuElements[COUNT];
public:
	MenuStudent();
	void show();
};

