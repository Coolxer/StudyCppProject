#include "Menu.h"

Menu::Menu()
{
	this->menuElements[0] = MenuElement(1, "Studenci");
	this->menuElements[1] = MenuElement(2, "Grono pedagogiczne");
	this->menuElements[2] = MenuElement(3, "Zajecia");
}

void Menu::show()
{
	for (int i = 0; i < COUNT; i++)
		this->menuElements[i].show();
}