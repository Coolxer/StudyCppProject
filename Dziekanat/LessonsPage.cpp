#include "LessonsPage.h"

#include "CmdManager.h"

LessonsPage::LessonsPage(Window* window) : Page(window)
{
	this->header = TextBox('#', "##     Lessons Page      ##");
}

void LessonsPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();
}

void LessonsPage::service()
{
	int option;

	do {
		option = CmdManager::listen();

		if (option == 9)
		{
			this->getWindow()->setActivePage(0);
			break;
		}
		else if (option == -1)
			continue;
		else
		{

		}
	} while (true);
}
