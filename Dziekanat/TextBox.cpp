#include "TextBox.h"
#include <iostream>

TextBox::TextBox(char type, std::string text, int length)
{
	this->type = type;
	this->text = text;
	this->length = length;
}

TextBox::TextBox(const TextBox& model)
{
	this->type = model.type;
	this->text = model.text;
	this->length = model.length;
}

TextBox& TextBox::operator = (const TextBox& model)
{
	this->type = model.type;
	this->text = model.text;
	this->length = model.length;

	return *this;
}

TextBox::~TextBox()
{

}

void TextBox::show()
{
	std::cout << std::endl;

	/* wyswietlenie linijki skladajacej sie ze znaku*/
	for (int i = 0; i < length; i++)
		std::cout << this->type;

	std::cout << std::endl << std::endl;

	// wyswietlenie tekstu
	std::cout << this->text << std::endl<< std::endl;

	/* wyswietlenie linijki skladajacej sie ze znaku*/
	for (int i = 0; i < length; i++)
		std::cout << this->type; 
	
	std::cout << std::endl;
}

