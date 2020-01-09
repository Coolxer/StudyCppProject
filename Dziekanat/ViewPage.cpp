#include "ViewPage.h"

#include "CmdManager.h"

#include <iostream>

ViewPage::ViewPage(Window* window, std::string headerText, ObjectList* objectList, int parentWindowIndex) : Page(window)
{
	this->header = TextBox('#', headerText);

	this->objectList = objectList;
	this->parentWindowIndex = parentWindowIndex;

	this->info = TextBox('*', "** Podaj nr operacji **");
}

void ViewPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	Object::showHeader();

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	bool isNotNull = this->objectList->showAll();

	if (!isNotNull)
		std::cout << "BRAK! ";

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
}

void ViewPage::service()
{
	int option;

	do {
		option = CmdManager::listen();

		if (option == 0)
		{
			this->getWindow()->setActivePage(this->parentWindowIndex);
			break;
		}
		else
		{
			continue;
			this->getWindow()->refresh();
		}
	} while (true);
}
