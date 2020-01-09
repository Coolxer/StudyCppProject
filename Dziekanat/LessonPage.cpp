#include "LessonPage.h"
#include <iostream>
#include "CmdManager.h"

#include "LessonList.h"
#include "StaffMember.h"

LessonPage::LessonPage(Window* window, std::string headerText) : MainPage(window, headerText)
{
	this->menu = Menu();

	this->menu.addMenuElement("Dodaj zajecie");
	this->menu.addMenuElement("Usun zajecie");
	this->menu.addMenuElement("Znajdz zajecie wedlug nazwy");
	this->menu.addMenuElement("Wyswietl prowadzacego zajecia");
	this->menu.addMenuElement("Wyswietl uczestnikow zajec");
	this->menu.addMenuElement("Wyswietl konkretny typ zajec");
	this->menu.addMenuElement("Wyswietl wszystkie zajecia");
	this->menu.addMenuElement("Wyswietl liczbe zajec");

	this->setMenu(&this->menu);

	this->lessonList = (LessonList*)&this->objectList;
}

void LessonPage::service()
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
			Lesson* lesson;
			std::string input;

			switch (option)
			{
			case 1:
				this->getWindow()->setActivePage(8);
				break;
			case 2:
				this->getWindow()->refresh();
				std::cout << "Podaj id zajec, ktore chcesz usunac: " << std::endl;
				std::cin >> id;

				id = this->objectList.removeObject(id);

				if (id == 0)
					std::cout << std::endl << "Nie ma takiego zajecia" << std::endl;
				else
					std::cout << std::endl << "Usunieto zajecie o id " << id;

				Sleep(2000);

				break;
			case 3:
				std::cout << "Podaj nazwe zajecia, ktorego szczegoly chcesz zobaczyc: " << std::endl;
				std::cin >> input;

				exists = lessonList->showByName(input);

				if (!exists)
					std::cout << std::endl << "Nie ma takich zajec" << std::endl;

				Sleep(2500);
				break;
			case 4:
				std::cout << "Podaj nazwe zajecia, ktorego prowadzacego chcesz zobaczyc: " << std::endl;
				std::cin >> input;

				lesson = this->lessonList->getByName(input);

				if (!lesson)
					std::cout << std::endl << "Nie ma takich zajec" << std::endl;
				else
				{
					StaffMember* staffMember = lesson->getStaffMember();

					if (!staffMember)
						std::cout << std::endl << "To zajecie nie ma przypisanego prowadzacego" << std::endl;
					else
						staffMember->show(true);
				}

				Sleep(2000);
					
				break;
			case 5:
				std::cout << "Podaj nazwe zajecia, ktorego uczestnikow chcesz zobaczyc: " << std::endl;
				std::cin >> input;

				lesson = this->lessonList->getByName(input);

				if (!lesson)
					std::cout << std::endl << "Nie ma takich zajec" << std::endl;
				else
				{
					bool ok = lesson->showStudents();

					if(!ok)
						std::cout << std::endl << "To zajecie nie ma uczestnikow" << std::endl;
				}

				Sleep(2500);
				break;
			case 6:
				this->getWindow()->setActivePage(9);
				break;
			case 7:
				std::cout << "Podaj typ zajec, ktore chcesz zobaczyc: " << std::endl;
				std::cin >> input;

				Lesson::showHeader();

				exists = this->lessonList->showSpecificType(input);

				if (!exists)
				{
					this->getWindow()->refresh();
					std::cout << std::endl << "Nie ma zajec typu " << input << std::endl;
				}

				Sleep(2500);
				break;
			case 8:
				std::cout << "Liczba zajec: " << this->lessonList->getNumberOfObjects() << std::endl;
				Sleep(2000);
				break;
			}

			this->getWindow()->refresh();
		}
	} while (true);
}
