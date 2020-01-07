#include "MenuStaff.h"

MenuStaff::MenuStaff()
{
	this->menuElements[0] = MenuElement(1, "Dodaj pracownika");
	this->menuElements[1] = MenuElement(2, "Usun pracownika");
	this->menuElements[2] = MenuElement(3, "Znajdz pracownika wedlug id");
	this->menuElements[3] = MenuElement(4, "Wyswietl wszystkich pracownikow");
	this->menuElements[4] = MenuElement(5, "Wyswietl profesorow");
	this->menuElements[5] = MenuElement(6, "Wyswietl liczbe pracownikow");
	this->menuElements[6] = MenuElement(7, "Przypisz pracownika do zajec");
}

void MenuStaff::show()
{
	for (int i = 0; i < 7; i++)
		this->menuElements[i].show();
}