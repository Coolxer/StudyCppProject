#include "Menu.h"
#include <iostream>

Menu::Menu()
{

}

void Menu::addMenuElement(std::string text)
{
	int index = this->menuElements.size();
	this->menuElements.push_back(MenuElement(index + 1, text));
}

void Menu::show()
{
	for (int i = 0; i < (int)this->menuElements.size(); i++)
		this->menuElements[i].show();
}
