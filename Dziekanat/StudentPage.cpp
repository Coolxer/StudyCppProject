#include "StudentPage.h"
#include <iostream>
#include "CmdManager.h"

StudentPage::StudentPage(Window* window, std::string headerText): MainPage(window, headerText)
{
	this->menu = Menu();

	this->menu.addMenuElement("Dodaj studenta");
	this->menu.addMenuElement("Usun studenta");
	this->menu.addMenuElement("Znajdz studenta wedlug indeksu");
	this->menu.addMenuElement("Wyswietl studentow z kierunku");
	this->menu.addMenuElement("Wyswietl studentow stacjonarnych");
	this->menu.addMenuElement("Wyswietl studentow zaocznych");
	this->menu.addMenuElement("Wyswietl wszystkich studentow");
	this->menu.addMenuElement("Wyswietl liczbe studentow");
	this->menu.addMenuElement("Zapisz studenta na zajecia");

	this->setMenu(&this->menu);

	this->studentList = (StudentList*)&this->objectList;
}

StudentPage::~StudentPage()
{
	delete this->studentList;
	delete this->lessonList;
}

void StudentPage::init(LessonList* lessonList)
{
	this->lessonList = lessonList;
}

void StudentPage::service()
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
			int index;
			bool exists;
			std::string input;

			Student* student;

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

				student = this->studentList->getObjectByIndex(index);

				if (!student)
					std::cout << "Nie ma takiego studenta" << std::endl;
				else
				{
					this->lessonList->removeStudentFromLessons(student);
					index = this->studentList->removeObject(student->getIndex());
					std::cout << std::endl << "Usunieto studenta o indeksie " << index;
					//delete student;
				}
				
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

				exists = this->studentList->showByIndex(index);

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

				Student::showHeader();

				exists = this->studentList->showByField();

				if (!exists)
				{
					this->getWindow()->refresh();
					std::cout << std::endl << "Nie studentow na tym kierunku" << std::endl;
				}
					
				Sleep(2500);
				break;
			case 6:
				exists = this->studentList->showByType("stacjonarne");

				if (!exists)
				{
					this->getWindow()->refresh();
					std::cout << std::endl << "Nie studentow stacjonarnych" << std::endl;
				}

				Sleep(2500);
				break;
			case 7:
				exists = this->studentList->showByType("zaoczne");

				if (!exists)
				{
					this->getWindow()->refresh();
					std::cout << std::endl << "Nie studentow zaocznych" << std::endl;
				}

				Sleep(2500);
				break;
			case 8:
				std::cout << "Liczba studentow: " << this->studentList->getNumberOfObjects() << std::endl;
				Sleep(2000);
				break;
			case 9:
				std::cout << "Podaj nr indeksu studenta, ktorego chcesz przypisac: " << std::endl;
				std::cin >> index;

				student = (Student*)this->studentList->getObjectByIndex(index);

				if (!student)
				{
					std::cout << "Nie ma takiego studenta" << std::endl;
					Sleep(1500);
				}		
				else
				{
					Lesson* lesson;

					std::cout << "Podaj nazwe zajec, do ktorego chcesz zapisac studenta: " << std::endl;
					std::cin >> input;

					lesson = this->lessonList->getByName(input);

					if (!lesson)
					{
						std::cout << "Nie ma takch zajec" << std::endl;
						Sleep(1500);
					}
					else
					{
						bool ok = lesson->addStudent(student);

						if (ok)
							std::cout << "Przypisano studenta do zajec";
						else
							std::cout << "Brak wolnych miejsc / Student juz jest przypisany do tych zajec";

						Sleep(1500);
					}
				}
				break;
			}
			this->getWindow()->refresh();
		}
	} while (true);
}
