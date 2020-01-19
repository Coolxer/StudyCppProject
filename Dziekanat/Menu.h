#pragma once
#include <vector>
#include <string>
#include "MenuElement.h"

/* Klasa reprezentujaca menu nawigacyjne */

class Menu
{
private:
	std::vector <MenuElement> menuElements; // elementy menu
public:
	Menu(); // konstruktor domyslny

	void addMenuElement(std::string text); // metoda dodaje nowy element do menu
	void addMenuBackElement(std::string text); // metoda dodaje nowy element o numerze 0 na samym koncu, element nawigacyjny

	void show(); // metoda wyswietla menu
};

