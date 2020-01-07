#include "StaffViewPage.h"

#include "CmdManager.h"

#include <iostream>

StaffViewPage::StaffViewPage(Window* window, StaffPage* staffPage) : Page(window)
{
	this->header = TextBox('#', "##    Lista pracownikow     ##");

	this->staffList = staffPage->getStaffList();
}

void StaffViewPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	StaffMember::showHeader();

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	bool isNotNull = this->staffList->showStaff();

	if (!isNotNull)
		std::cout << "BRAK PRACOWNIKOW! ";

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
}

void StaffViewPage::service()
{
	int option;

	do {
		option = CmdManager::listen();

		if (option == 9)
		{
			this->getWindow()->setActivePage(2);
			break;
		}
		else
		{
			continue;
			this->getWindow()->refresh();
		}
	} while (true);
}
