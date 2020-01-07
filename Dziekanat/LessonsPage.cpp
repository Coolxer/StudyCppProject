#include "LessonsPage.h"
#include <iostream>
#include "CmdManager.h"

LessonsPage::LessonsPage(Window* window) : Page(window)
{
	this->header = TextBox('#', "##     Zajecia      ##");

	this->menuElements[0] = MenuElement(1, "Dodaj zajecie");
	this->menuElements[1] = MenuElement(2, "Usun zajecie"); //wedlug indeksu
	this->menuElements[2] = MenuElement(3, "Znajdz zajecie wedlug id");
	this->menuElements[3] = MenuElement(4, "Wyswietl wszystkie zajecia");
	this->menuElements[4] = MenuElement(5, "Wyswietl konkretny typ zajec");
	this->menuElements[5] = MenuElement(6, "Wyswietl liczbe zajec");

	this->info = TextBox('*', "** Podaj nr operacji **");

	this->lessonsList = LessonsList();
}

LessonsList* LessonsPage::getStaffList()
{
	return &this->lessonsList;
}

void LessonsPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	for (int i = 0; i < 6; i++)
		this->menuElements[i].show();

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
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
			int id;
			bool exists;
			std::string input;

			switch (option)
			{
			case 1:
				this->getWindow()->setActivePage(8);
				break;
			case 2:
				this->getWindow()->refresh();
				std::cout << "Podaj id zajecia, ktore chcesz usunac: " << std::endl;
				std::cin >> id;

				if (!std::cin.good())
				{
					std::cout << "id to liczba! " << std::endl;
					Sleep(1000);
					break;
				}

				id = this->lessonsList.removeLesson(id);

				if (id == 0)
					std::cout << std::endl << "Nie ma takiego zajecia" << std::endl;
				else
					std::cout << std::endl << "Usunieto zajecie o id " << id;

				Sleep(2000);

				break;
			case 3:
				std::cout << "Podaj id zajecia, ktorego szczegoly chcesz zobaczyc: " << std::endl;
				std::cin >> id;

				if (!std::cin.good())
				{
					std::cout << "id to liczba! " << std::endl;
					Sleep(1000);
					break;
				}

				exists = this->lessonsList.showLessonById(id);

				if (!exists)
					std::cout << std::endl << "Nie ma takiego zajecia" << std::endl;

				Sleep(2500);
				break;
			case 4:
				this->getWindow()->setActivePage(9);
				break;
			case 5:
				std::cout << "Podaj typ zajec, ktore chcesz zobaczyc: " << std::endl;
				std::cin >> input;

				Lesson::showHeader();

				exists = this->lessonsList.showSpecificLessons(input);

				if (!exists)
				{
					this->getWindow()->refresh();
					std::cout << std::endl << "Nie ma zajec typu " << input <<  std::endl;
				}

				Sleep(2500);
				break;
			case 6:
				std::cout << "Liczba zajec: " << this->lessonsList.getNumberofLessons() << std::endl;
				Sleep(2000);
				break;
			}

			this->getWindow()->refresh();
		}
	} while (true);
}
