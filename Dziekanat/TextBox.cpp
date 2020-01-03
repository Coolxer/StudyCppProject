#include "TextBox.h"
#include <iostream>

TextBox::TextBox(char type, std::string text)
{
	this->type = type;
	this->text = text;
}

void TextBox::show()
{
	std::cout << std::endl;

	for (int i = 0; i < 25; i++)
		std::cout << this->type;

	std::cout << std::endl << std::endl;

	std::cout << this->text << std::endl<< std::endl;

	for (int i = 0; i < 25; i++)
		std::cout << this->type; 
	
	std::cout << std::endl;
}

