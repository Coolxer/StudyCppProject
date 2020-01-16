#include "Menu.h"
#include <iostream>

Menu::Menu()
{

}

void Menu::addMenuElement(std::string text)
{
	int index = this->menuElements.size(); // pobranie ilosci elementow menu
	this->menuElements.push_back(MenuElement(index + 1, text)); // dodanie nowego elementu do menu, z numerem zwiekszonym o 1
}

void Menu::show()
{
	for (int i = 0; i < (int)this->menuElements.size(); i++)
		this->menuElements[i].show(); // wyswietlenie elementu menu
}
