#include "ViewPage.h"

#include "CmdManager.h"

#include <iostream>

ViewPage::ViewPage(Window* window, std::string headerText, int parentWindowIndex) : Page(window)
{
	this->header = TextBox('#', headerText);

	this->parentWindowIndex = parentWindowIndex;

	this->info = TextBox('*', "** Podaj nr operacji **");

	//this->objectList = new ObjectList();
}

ViewPage::~ViewPage()
{
	//delete this->objectList;
}

void ViewPage::init(ObjectList* objectList)
{
	this->objectList = objectList;
}

void ViewPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show(); // wyswietlenie naglowka

	/*
	if(this->objectList->getNumberOfObjects() != 0)
	{
		//this->objectList->sh
	}*/

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	this->objectList->showAll(); // wyswietlenie obiektow z listy

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show(); // wyswietlenie informacji
}

void ViewPage::service()
{
	int option;

	do {
		option = CmdManager::listen();  // pobranie numeru operacji do wykonania

		if (option == 0)
		{
			this->getWindow()->setActivePage(this->parentWindowIndex); // powrot do strony nadrzednej
			break;
		}
		else
		{
			continue;
			this->getWindow()->refresh(); // odswiezenie okna
		}
	} while (true);
}
