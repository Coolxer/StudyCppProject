#pragma once
#include "MenuElement.h"

#define COUNT 6

class MenuLesson
{
private:
	MenuElement menuElements[COUNT];
public:
	MenuLesson();
	void show();
};
