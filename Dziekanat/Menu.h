#pragma once
#include <string>
#include "MenuElement.h"

/* Klasa reprezentujaca menu nawigacyjne */

class Menu
{
private:
	MenuElement* menuElements; // elementy menu
	int size; // ilosc elementow w menu
public:
	Menu(); // konstruktor domyslny
	Menu(const Menu& model); // konstruktor kopiujacy
	Menu& operator = (const Menu& model); // przeciazenie operatora przypisania
	~Menu(); // destruktor

	MenuElement* getMenuElement(int id) const;
	int getSize() const;

	void addMenuElement(std::string text); // metoda dodaje nowy element do menu
	void addMenuBackElement(std::string text); // metoda dodaje nowy element o numerze 0 na samym koncu, element nawigacyjny

	void show(); // metoda wyswietla menu
};

