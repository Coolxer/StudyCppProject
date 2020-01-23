#include "MenuPage.h"

MenuPage::MenuPage(Window* window) : MainPage(window, "              DZIEKANAT ")
{
	this->menu = Menu(); // stworzenie obiektu typu Menu

	/* Dodawanie elementow do menu */
	this->menu.addMenuElement("Studenci"); 
	this->menu.addMenuElement("Grono pedagogiczne");
	this->menu.addMenuElement("Zajecia");
	this->menu.addMenuBackElement("Wyjscie z programu");

	this->setMenu(&this->menu); // ustawienie menu
}

MenuPage::MenuPage(const MenuPage& model)
{
	this->menu = model.menu;
}

MenuPage& MenuPage::operator = (const MenuPage& model)
{
	this->menu = model.menu;

	return *this;
}

MenuPage::~MenuPage()
{

}

void MenuPage::service()
{
	int option;

	do {
		option = CmdManager::listen(); // pobranie numeru operacji do wykonania

		if (option == 0)
			break;
		else if (option == -1)
		{
			Sleep(1000);
			this->getWindow()->refresh();
			continue;
		}
		else
		{
			this->getWindow()->setActivePage(option); // przejscie do strony o podanym numerze
			break;
		}
	} while (true);
}