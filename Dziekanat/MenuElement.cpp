#include "MenuElement.h"

#include <iostream>

MenuElement::MenuElement(int number, std::string name)
{
	this->number = number;
	this->name = name;
}

MenuElement::MenuElement(const MenuElement& model)
{
	this->number = model.number;
	this->name = model.number;
}

MenuElement& MenuElement::operator = (const MenuElement& model)
{
	this->number = model.number;
	this->name = model.name;

	return *this;
}

MenuElement::~MenuElement()
{

}

void MenuElement::show()
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << " " << this->number << ".| " << this->name << std::endl;
}