#include "MenuLesson.h"

MenuLesson::MenuLesson()
{
	this->menuElements[0] = MenuElement(1, "Dodaj zajecie");
	this->menuElements[1] = MenuElement(2, "Usun zajecie");
	this->menuElements[2] = MenuElement(3, "Znajdz zajecie wedlug id");
	this->menuElements[3] = MenuElement(4, "Wyswietl wszystkie zajecia");
	this->menuElements[4] = MenuElement(5, "Wyswietl konkretny typ zajec");
	this->menuElements[5] = MenuElement(6, "Wyswietl liczbe zajec");
}

void MenuLesson::show()
{
	for (int i = 0; i < 6; i++)
		this->menuElements[i].show();
}