#include "MenuPage.h"

MenuPage::MenuPage(int index, HANDLE* console): Page(index, console)
{
	this->tileBox = TextBox("##     DZIEKANAT     ##");
	this->infoBox = TextBox("## Podaj nr operacji ##");
}

void MenuPage::draw()
{
	SetConsoleTextAttribute(this->getConsole(), FOREGROUND_GREEN);
	this->tileBox.show();
	SetConsoleTextAttribute(this->getConsole(), FOREGROUND_RED);
	this->menu.show();
	SetConsoleTextAttribute(this->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->infoBox.show();
}