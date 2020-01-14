#pragma once
#include <string>

/* Klasa reprezentujaca element menu nawigacyjnego */

class MenuElement
{
private:
	int number; // numer elementu
	std::string name; // tekst elementu

public:
	MenuElement() {} // konstruktor domyslny
	MenuElement(int number, std::string name); // konstruktor z 2 parametrami: numerem elementu oraz tekstem elementu

	void show(); // metoda wyswietla element menu
};