#include "ViewPage.h"

#include "CmdManager.h"

#include <iostream>

ViewPage::ViewPage(Window* window, std::string headerText, int parentWindowIndex) : Page(window)
{
	this->header = TextBox('#', headerText);

	this->parentWindowIndex = parentWindowIndex;

	this->info = TextBox('*', "** 0 -> powrot do poprzedniej strony. **");

}

ViewPage::ViewPage(const ViewPage& model)
{
	this->header = model.header;
	this->info = model.header;

	this->objectList = model.objectList;
	this->parentWindowIndex = model.parentWindowIndex;
}

ViewPage& ViewPage::operator = (const ViewPage& model)
{
	this->header = model.header;
	this->info = model.header;

	this->objectList = model.objectList;
	this->parentWindowIndex = model.parentWindowIndex;

	return *this;
}

ViewPage::~ViewPage()
{
	
}

void ViewPage::init(ObjectList* objectList)
{
	this->objectList = objectList;
}

void ViewPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show(); // wyswietlenie naglowka

	if (this->objectList->getNumberOfObjects() != 0)
		this->objectList->getObjectByRealIndex(0)->showHeader();	

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
