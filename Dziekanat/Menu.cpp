#include "Menu.h"

Menu::Menu()
{
	this->menuElements[0] = MenuElement(1, "Wykladowcy");
	this->menuElements[1] = MenuElement(2, "Studenci");
	this->menuElements[2] = MenuElement(3, "Grupy");
	this->menuElements[3] = MenuElement(4, "Sale");
	this->menuElements[4] = MenuElement(5, "Budynki");
}

void Menu::show()
{
	for (int i = 0; i < COUNT; i++)
		this->menuElements[i].show();
}