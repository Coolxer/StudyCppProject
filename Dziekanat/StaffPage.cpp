#include "StaffPage.h"

StaffPage::StaffPage(Window* window) : MainPage(window, " GRONO PEDAGOGICZNE SERWIS ")
{
	this->menu.addMenuElement("Dodaj pracownika");
	this->menu.addMenuElement("Usun pracownika");
	this->menu.addMenuElement("Znajdz pracownika wedlug id");
	this->menu.addMenuElement("Wyswietl profesorow");
	this->menu.addMenuElement("Wyswietl wszystkich pracownikow");
	this->menu.addMenuElement("Wyswietl liczbe pracownikow");
	this->menu.addMenuElement("Przypisz pracownika do zajec");

	this->setMenu(&this->menu);
}

StaffPage::~StaffPage()
{
	delete this->lessonList;
}

StaffList* StaffPage::getStaffList()
{
	return &this->staffList;
}

void StaffPage::init(LessonList* lessonList)
{
	this->lessonList = lessonList;
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

			StaffMember* staffMember;

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

				staffMember = (StaffMember*)this->staffList.getObjectByIndex(id);

				exists = this->staffList.removeObject(staffMember->getIndex());

				if (!exists)
					std::cout << std::endl << "Nie ma takiego pracownika" << std::endl;
				else
				{
					std::cout << std::endl << "Usunieto pracownika o indeksie " << id;
					this->lessonList->removeStaffMemberFromLessons(staffMember);
				}
					
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

				exists = this->staffList.showByIndex(id);

				if (!exists)
					std::cout << std::endl << "Nie ma takiego pracownika" << std::endl;

				Sleep(2500);
				break;
			case 4:

				//StaffMember::showHeader();

				exists = this->staffList.showProfessors();

				if (!exists)
				{
					this->getWindow()->refresh();
					std::cout << std::endl << "Nie ma profesorow" << std::endl;
				}

				Sleep(2500);
				break;
			case 5:
				this->getWindow()->setActivePage(7);
				break;	
			case 6:
				std::cout << "Liczba pracownikow: " << this->staffList.getNumberOfObjects() << std::endl;
				Sleep(2000);
				break;
			case 7:
				std::cout << "Podaj nr id pracownika, ktorego chcesz przypisac: " << std::endl;
				std::cin >> id;

				staffMember = (StaffMember*)this->staffList.getObjectByIndex(id);

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

					lesson = this->lessonList->getByName(input);

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
