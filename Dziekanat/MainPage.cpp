#include "MainPage.h"
#include <iostream>
#include "CmdManager.h"

MainPage::MainPage(Window* window, std::string headerText) : Page(window)
{
	this->header = TextBox('#', headerText);
	this->info = TextBox('*', "**         Podaj nr operacji          **");
}

MainPage::MainPage(const MainPage& model)
{
	this->header = model.header;
	this->menu = model.menu;
	this->info = model.info;
}

MainPage& MainPage::operator = (const MainPage& model)
{
	this->header = model.header;
	this->menu = model.menu;
	this->info = model.info;

	return *this;
}

MainPage::~MainPage()
{

}

void MainPage::setMenu(Menu* menu)
{
	this->menu = *menu; // ustawienie menu
}

void MainPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show(); // wyswietlenie naglowka

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	this->menu.show(); // wyswietlenie menu

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show(); // wyswietlenie informacji
}