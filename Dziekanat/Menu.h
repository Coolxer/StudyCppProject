#pragma once
#include <vector>
#include <string>
#include "MenuElement.h"

class Menu
{
private:
	std::vector <MenuElement> menuElements;
public:
	Menu();

	void addMenuElement(std::string text);

	void show();
};

