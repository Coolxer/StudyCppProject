#include "StudentsViewPage.h"

#include "CmdManager.h"

#include <iostream>

StudentsViewPage::StudentsViewPage(Window* window, StudentsPage* studentsPage) : Page(window)
{
	this->header = TextBox('#', "##    Lista studentow     ##");

	this->studentsList = studentsPage->getStudentsList();
}

void StudentsViewPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	Student::showHeader();

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	bool isNotNull = this->studentsList->showAllStudents();

	if (!isNotNull)
		std::cout << "BRAK STUDENTOW! ";

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
}

void StudentsViewPage::service()
{
	int option;

	do {
		option = CmdManager::listen();

		if (option == 9)
		{
			this->getWindow()->setActivePage(1);
			break;
		}
		else
		{
			continue;
			this->getWindow()->refresh();
		}
	} while (true);
}
