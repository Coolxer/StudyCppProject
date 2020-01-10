#include "MenuPage.h"

MenuPage::MenuPage(Window* window) : MainPage(window, " DZIEKANAT ")
{
	this->menu = Menu();

	this->menu.addMenuElement("Studenci");
	this->menu.addMenuElement("Grono pedagogiczne");
	this->menu.addMenuElement("Zajecia");

	this->setMenu(&this->menu);
}

void MenuPage::service()
{
	int option;

	do {
		option = CmdManager::listen();

		if (option == 0)
			break;
		else if (option == -1)
			continue;
		else
		{
			this->getWindow()->setActivePage(option);
			break;
		}
	} while (true);
}