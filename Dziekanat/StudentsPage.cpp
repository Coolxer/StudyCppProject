#include "StudentsPage.h"
#include <iostream>
#include "CmdManager.h"

StudentsPage::StudentsPage(Window* window): Page(window)
{
	this->header = TextBox('#', "##     Studenci      ##");
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
	this->menuStudent.show();

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
			int index;
			bool exists;
			std::string input;

			switch (option)
			{
			case 1:
				this->getWindow()->setActivePage(4);
				break;
			case 2:
				this->getWindow()->refresh();
				std::cout << "Podaj nr indeksu studenta, ktorego chcesz usunac: " << std::endl;
				std::cin >> index;

				if (!std::cin.good())
				{
					std::cout << "indeks to liczba! " << std::endl;
					Sleep(1000);
					break;
				}
					
				index = this->studentsList.removeStudent(index);

				if (index == 0)
					std::cout << std::endl << "Nie ma takiego studenta" << std::endl;
				else
					std::cout << std::endl << "Usunieto studenta o indeksie " << index;

				Sleep(2000);

				break;
			case 3:
				std::cout << "Podaj nr indeksu studenta, ktorego dane chcesz zobaczyæ: " << std::endl;
				std::cin >> index;

				if (!std::cin.good())
				{
					std::cout << "indeks to liczba! " << std::endl;
					Sleep(1000);
					break;
				}

				exists = this->studentsList.showStudentbyIndex(index);

				if (!exists)
					std::cout << std::endl << "Nie ma takiego studenta" << std::endl;

				Sleep(2500);
				break;
			case 4:
				this->getWindow()->setActivePage(5);
				break;
			case 5:
				std::cout << "Podaj nazwe kierunku studiow" << std::endl;
				std::cin >> input;

				std::cout << " Imie " << " Nazwisko " << " Wiek " << " Indeks " << " Kierunek " << " Stopien " << " Rok " << " Typ " << std::endl;

				exists = this->studentsList.showStudentsByField(input);

				if (!exists)
				{
					this->getWindow()->refresh();
					std::cout << std::endl << "Nie studentow na tym kierunku" << std::endl;
				}
					
				Sleep(2500);
				break;
			case 6:
				exists = this->studentsList.showStudentsByType("stacjonarne");

				if (!exists)
				{
					this->getWindow()->refresh();
					std::cout << std::endl << "Nie studentow stacjonarnych" << std::endl;
				}

				Sleep(2500);
				break;
			case 7:
				exists = this->studentsList.showStudentsByType("zaoczne");

				if (!exists)
				{
					this->getWindow()->refresh();
					std::cout << std::endl << "Nie studentow zaocznych" << std::endl;
				}

				Sleep(2500);
				break;
			case 8:
				std::cout << "Liczba studentow: " << this->studentsList.getNumberOfStudents() << std::endl;
				Sleep(2000);
				break;
			}

			this->getWindow()->refresh();
		}
	} while (true);
}
