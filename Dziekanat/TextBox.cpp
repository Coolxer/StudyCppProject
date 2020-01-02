#include "TextBox.h"
#include <iostream>

TextBox::TextBox(std::string text)
{
	this->text = text;
}

void TextBox::show()
{
	std::cout << std::endl;
	std::cout << "#######################" << std::endl;
	std::cout << this->text << std::endl;
	std::cout << "#######################" << std::endl;
}

