#include "TextBox.h"
#include <iostream>

TextBox::TextBox(char type, std::string text)
{
	this->type = type;
	this->text = text;
}

TextBox::TextBox(const TextBox& model)
{
	this->type = model.type;
	this->text = model.text;
}

TextBox& TextBox::operator = (const TextBox& model)
{
	this->type = model.type;
	this->text = model.text;

	return *this;
}

TextBox::~TextBox()
{

}

void TextBox::show()
{
	std::cout << std::endl;

	/* wyswietlenie linijki skladajacej sie ze znaku*/
	for (int i = 0; i < 40; i++)
		std::cout << this->type;

	std::cout << std::endl << std::endl;

	// wyswietlenie tekstu
	std::cout << this->text << std::endl<< std::endl;

	/* wyswietlenie linijki skladajacej sie ze znaku*/
	for (int i = 0; i < 40; i++)
		std::cout << this->type; 
	
	std::cout << std::endl;
}

