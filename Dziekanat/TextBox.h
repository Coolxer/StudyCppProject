#pragma once
#include <string>

/* Klasa reprezentujaca tekst otoczony ramka */

class TextBox
{
private:
	char type; // znak reprezentujacy ramke
	std::string text; // tekst
public:
	TextBox() {} // konstruktor
	TextBox(char type, std::string text); // konstruktor parametrowy
	void show(); // metoda wyswietla tekst z ramka
};

