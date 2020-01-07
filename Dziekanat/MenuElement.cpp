#include "MenuElement.h"

#include <iostream>

MenuElement::MenuElement(int number, std::string name)
{
	this->number = number;
	this->name = name;
}

void MenuElement::show()
{
	std::cout << "--------------------------" << std::endl;
	std::cout << " " << this->number << ".| " << this->name << std::endl;
}