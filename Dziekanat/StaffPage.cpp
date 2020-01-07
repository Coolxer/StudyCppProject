#include "StaffPage.h"
#include <iostream>
#include "CmdManager.h"

StaffPage::StaffPage(Window* window) : Page(window)
{
	this->header = TextBox('#', "##     Pracownicy      ##");
	this->info = TextBox('*', "** Podaj nr operacji **");

	this->staffList = StaffList();
}

StaffList* StaffPage::getStaffList()
{
	return &this->staffList;
}

void StaffPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	this->menuStaff.show();

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
}

void StaffPage::service()
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
			int id;
			bool exists;
			std::string input;

			switch (option)
			{
			case 1:
				this->getWindow()->setActivePage(6);
				break;
			case 2:
				this->getWindow()->refresh();
				std::cout << "Podaj id pracownika, ktorego chcesz zwolnic: " << std::endl;
				std::cin >> id;

				if (!std::cin.good())
				{
					std::cout << "id to liczba! " << std::endl;
					Sleep(1000);
					break;
				}

				id = this->staffList.removeMember(id);

				if (id == 0)
					std::cout << std::endl << "Nie ma takiego pracownika" << std::endl;
				else
					std::cout << std::endl << "Usunieto pracownika o indeksie " << id;

				Sleep(2000);

				break;
			case 3:
				std::cout << "Podaj id pracownika, ktorego dane chcesz zobaczyæ: " << std::endl;
				std::cin >> id;

				if (!std::cin.good())
				{
					std::cout << "id to liczba! " << std::endl;
					Sleep(1000);
					break;
				}

				exists = this->staffList.showMemberbyId(id);

				if (!exists)
					std::cout << std::endl << "Nie ma takiego pracownika" << std::endl;

				Sleep(2500);
				break;
			case 4:
				this->getWindow()->setActivePage(7);
				break;
			case 5:

				StaffMember::showHeader();

				exists = this->staffList.showProfessors();

				if (!exists)
				{
					this->getWindow()->refresh();
					std::cout << std::endl << "Nie ma profesorow" << std::endl;
				}

				Sleep(2500);
				break;
			case 6:
				std::cout << "Liczba pracownikow: " << this->staffList.getNumberOfMembers() << std::endl;
				Sleep(2000);
				break;
			}

			this->getWindow()->refresh();
		}
	} while (true);
}
