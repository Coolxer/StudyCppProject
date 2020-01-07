#include "LessonsViewPage.h"

#include "CmdManager.h"

#include <iostream>

LessonsViewPage::LessonsViewPage(Window* window, LessonsPage* lessonsPage) : Page(window)
{
	this->header = TextBox('#', "##    Lista zajec     ##");

	this->lessonsList = lessonsPage->getStaffList();
}

void LessonsViewPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	Lesson::showHeader();

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	bool isNotNull = this->lessonsList->showLessons();

	if (!isNotNull)
		std::cout << "BRAK ZAJEC! ";

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
}

void LessonsViewPage::service()
{
	int option;

	do {
		option = CmdManager::listen();

		if (option == 9)
		{
			this->getWindow()->setActivePage(3);
			break;
		}
		else
		{
			continue;
			this->getWindow()->refresh();
		}
	} while (true);
}
