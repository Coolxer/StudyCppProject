#include "MainPage.h"
#include <iostream>
#include "CmdManager.h"

MainPage::MainPage(Window* window, std::string headerText) : Page(window)
{
	this->header = TextBox('#', headerText);
	this->objectList = ObjectList();
	this->info = TextBox('*', "** Podaj nr operacji **");
}

ObjectList* MainPage::getObjectList()
{
	return &this->objectList;
}

void MainPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	this->menuLesson.show();

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
}

void MainPage::service()
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
				std::cout << "Podaj nazwe zajecia, ktorego szczegoly chcesz zobaczyc: " << std::endl;
				std::cin >> input;

				exists = this->lessonsList.showLessonByName(input);

				if (!exists)
					std::cout << std::endl << "Nie ma takich zajec" << std::endl;

				Sleep(2500);
				break;
			case 4:
				std::cout << "Podaj nazwe zajecia, ktorego prowadzacego chcesz zobaczyc: " << std::endl;
				std::cin >> input;

				exists = this->lessonsList.getLessonByName(input);

				if (!exists)
					std::cout << std::endl << "Nie ma takich zajec" << std::endl;
				else
				{
					StaffMember* staffMember = this->lessonsList.getLessonByName(input)->getStaffMember();

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

				exists = this->lessonsList.getLessonByName(input);

				if (!exists)
					std::cout << std::endl << "Nie ma takich zajec" << std::endl;
				else
				{
					bool ok = this->lessonsList.getLessonByName(input)->showStudents();

					if (!ok)
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

				exists = this->lessonsList.showSpecificLessons(input);

				if (!exists)
				{
					this->getWindow()->refresh();
					std::cout << std::endl << "Nie ma zajec typu " << input << std::endl;
				}

				Sleep(2500);
				break;
			case 8:
				std::cout << "Liczba zajec: " << this->lessonsList.getNumberOfLessons() << std::endl;
				Sleep(2000);
				break;
			}

			this->getWindow()->refresh();
		}
	} while (true);
}
