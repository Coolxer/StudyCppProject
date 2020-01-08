#include "Menu.h"

Menu::Menu()
{

}

void Menu::addMenuElement(std::string text)
{
	int index = this->menuElements.size();
	this->menuElements.push_back(MenuElement(index, text));
}

void Menu::show()
{
	for (int i = 0; (int)this->menuElements.size(); i++)
		this->menuElements[i].show();
}
