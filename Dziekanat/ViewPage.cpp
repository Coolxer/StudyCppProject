#include "ViewPage.h"

#include "CmdManager.h"

#include <iostream>

ViewPage::ViewPage(Window* window, std::string headerText, int parentWindowIndex) : Page(window)
{
	this->header = TextBox('#', headerText);

	this->parentWindowIndex = parentWindowIndex;

	this->info = TextBox('*', "** Podaj nr operacji **");
}

void ViewPage::init(ObjectList* objectList)
{
	this->objectList = objectList;
	//std::cout << objectList->getNumberOfObjects() << std::endl;
	//Sleep(3000);
}

void ViewPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	if(this->objectList->getNumberOfObjects() != 0)
	{
		//Object* object = (Object*)&this->objectList[0];
		//object->showHeader();
	}

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	bool isEmpty = this->objectList->showAll();

	if (!isEmpty)
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
