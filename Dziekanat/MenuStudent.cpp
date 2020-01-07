#include "MenuStudent.h"

MenuStudent::MenuStudent()
{
	this->menuElements[0] = MenuElement(1, "Dodaj studenta");
	this->menuElements[1] = MenuElement(2, "Usun studenta"); 
	this->menuElements[2] = MenuElement(3, "Znajdz studenta wedlug indeksu");
	this->menuElements[3] = MenuElement(4, "Wyswietl wszystkich studentow");
	this->menuElements[4] = MenuElement(5, "Wyswietl studentow z kierunku");
	this->menuElements[5] = MenuElement(6, "Wyswietl studentow stacjonarnych");
	this->menuElements[6] = MenuElement(7, "Wyswietl studentow zaocznych");
	this->menuElements[7] = MenuElement(8, "Wyswietl liczbe studentow");
}

void MenuStudent::show()
{
	for (int i = 0; i < COUNT; i++)
		this->menuElements[i].show();
}