#include "StaffPage.h"
#include <iostream>
#include "CmdManager.h"

StaffPage::StaffPage(Window* window) : Page(window)
{
	this->header = TextBox('#', "##     Pracownicy      ##");
	this->info = TextBox('*', "** Podaj nr operacji **");

	this->staffList = StaffList();
}

void StaffPage::init(LessonsList* lessonsList)
{
	this->lessonsList = lessonsList;
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

		if (option == 0)
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
			case 7:
				StaffMember * staffMember;
				std::cout << "Podaj nr id pracownika, ktorego chcesz przypisac: " << std::endl;
				std::cin >> id;

				staffMember = this->staffList.getStaffMemberByIndex(id);

				if (!staffMember)
				{
					std::cout << "Nie ma takiego pracownika" << std::endl;
					Sleep(1500);
				}
				else
				{
					Lesson* lesson;

					std::cout << "Podaj nazwe zajecia, do ktorego chcesz przypisac pracownika: " << std::endl;
					std::cin >> input;

					lesson = this->lessonsList->getLessonByName(input);

					if (!lesson)
					{
						std::cout << "Nie ma takiego zajecia" << std::endl;
						Sleep(1500);
					}
					else
					{
						bool ok = lesson->setStaffMember(staffMember);

						if (ok)
						{
							std::cout << "Przypisano pracownika do zajecia";
							staffMember->increaseLessons();
						}
						else
							std::cout << "To zajecie ma juz swojego prowadzacego";

						Sleep(1500);
					}
				}
				break;
			}	
			this->getWindow()->refresh();
		}
	} while (true);
}
