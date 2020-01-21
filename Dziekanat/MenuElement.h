#pragma once
#include <string>

/* Klasa reprezentujaca element menu nawigacyjnego */

class MenuElement
{
private:
	int number; // numer elementu
	std::string name; // tekst elementu

public:
	MenuElement(int number = 0, std::string name = ""); // konstruktor z 2 parametrami: numerem elementu oraz tekstem elementu
	MenuElement(const MenuElement& model); // konstruktor kopiujacy
	MenuElement& operator = (const MenuElement& model); // przeciazenie operatora przypisania
	~MenuElement(); // destruktor

	void show(); // metoda wyswietla element menu
};