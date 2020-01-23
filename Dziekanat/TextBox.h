#pragma once
#include <string>

/* Klasa reprezentujaca tekst otoczony ramka */

class TextBox
{
private:
	char type; // znak reprezentujacy ramke
	std::string text; // tekst
	int length; // dlugosc ramki
public:
	TextBox(char type = ' ', std::string text = "", int length = 40); // konstruktor domyslny
	TextBox(const TextBox& model); // konstruktor kopiujacy
	TextBox& operator = (const TextBox& model); // przeciazenie operatora przypisania
	~TextBox(); // destruktor

	void show(); // metoda wyswietla tekst z ramka
};

