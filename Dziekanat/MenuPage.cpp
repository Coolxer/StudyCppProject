#include "MenuPage.h"
#include "CmdManager.h"

MenuPage::MenuPage(Window *window): Page(window)
{
	this->titleBox = TextBox('#', "##     DZIEKANAT     ##");
	this->infoBox = TextBox('*', "** Podaj nr operacji **");
}

void MenuPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->titleBox.show();
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	this->menu.show();
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->infoBox.show();
}

void MenuPage::service()
{
	int option;

	do {
		option = CmdManager::listen();

		if (option == 9)
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