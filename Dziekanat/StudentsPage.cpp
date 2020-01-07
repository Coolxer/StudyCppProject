#include "StudentsPage.h"

#include "CmdManager.h"

StudentsPage::StudentsPage(Window* window): Page(window)
{
	this->header = TextBox('#', "##     Students Page      ##");
	
	this->menuElements[0] = MenuElement(1, "Dodaj studenta");
	this->menuElements[1] = MenuElement(2, "Usun studenta"); //wedlug indeksu
	this->menuElements[3] = MenuElement(3, "Znajdz studenta wedlug indeksu");
	this->menuElements[2] = MenuElement(4, "Wyswietl wszystkich studentow");
	this->menuElements[4] = MenuElement(5, "Wyswietl studentow z wydzialu");
	this->menuElements[5] = MenuElement(6, "Wyswietl studentow stacjonarnych");
	this->menuElements[6] = MenuElement(7, "Wyswietl studentow zaocznych");
	this->menuElements[7] = MenuElement(8, "Wyswietl liczbe studentow");

	this->info = TextBox('*', "** Podaj nr operacji **");

	this->studentsList = StudentsList();
}

StudentsList *StudentsPage::getStudentsList()
{
	return &this->studentsList;
}

void StudentsPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	for (int i = 0; i < 8; i++)
		this->menuElements[i].show();

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
}

void StudentsPage::service()
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
			switch (option)
			{
			case 1:
				this->getWindow()->setActivePage(3);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			}
		}
	} while (true);
}
