#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	this->size = 0;
	this->menuElements = nullptr;
}

Menu::Menu(const Menu& model)
{
	this->size = model.getSize();

	this->menuElements = model.menuElements;;
}

Menu& Menu::operator = (const Menu& model)
{
	delete[] this->menuElements;

	this->size = model.size;

	this->menuElements = model.menuElements;

	return *this;
}

Menu::~Menu()
{
	delete[] this->menuElements;
}

MenuElement* Menu::getMenuElement(int id) const
{
	return &this->menuElements[id];
}

int Menu::getSize() const
{
	return this->size;
}

void Menu::addMenuElement(std::string text)
{
	MenuElement* tmp = new MenuElement[this->size + 1];
	std::copy(this->menuElements, this->menuElements + this->size, tmp);

	this->size++;

	delete[] this->menuElements;
	this->menuElements = tmp;

	this->menuElements[this->size - 1] = MenuElement(this->size, text);
}

void Menu::addMenuBackElement(std::string text)
{
	MenuElement* tmp = new MenuElement[this->size + 1];
	std::copy(this->menuElements, this->menuElements + this->size, tmp);

	this->size++;

	delete[] this->menuElements;
	this->menuElements = tmp;

	this->menuElements[this->size - 1] = MenuElement(0, text);
}

void Menu::show()
{
	for (int i = 0; i < this->size; i++)
		this->menuElements[i].show(); // wyswietlenie elementu menu
}
