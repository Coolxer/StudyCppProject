#include "StudentPage.h"

StudentPage::StudentPage(Window* window) : MainPage(window, " STUDENT SERWIS ")
{
	/* Dodawanie elementow do menu */
	this->menu.addMenuElement("Dodaj studenta");
	this->menu.addMenuElement("Usun studenta");
	this->menu.addMenuElement("Znajdz studenta wedlug indeksu");
	this->menu.addMenuElement("Wyswietl studentow z kierunku");
	this->menu.addMenuElement("Wyswietl studentow stacjonarnych");
	this->menu.addMenuElement("Wyswietl studentow zaocznych");
	this->menu.addMenuElement("Wyswietl wszystkich studentow");
	this->menu.addMenuElement("Wyswietl liczbe studentow");
	this->menu.addMenuElement("Zapisz studenta na zajecia");

	this->setMenu(&this->menu); // ustawienie menu dla strony
}

StudentPage::~StudentPage()
{
	
}

StudentList* StudentPage::getStudentList()
{
	return &this->studentList;
}

void StudentPage::init(LessonList* lessonList)
{
	this->lessonList = lessonList;
}

void StudentPage::service()
{
	int option;

	do {
		option = CmdManager::listen(); // pobranie numeru operacji do wykonania

		if (option == 0)
		{
			this->getWindow()->setActivePage(0); // powrot do strony glownej
			break;
		}
		else if (option == -1)
			continue;
		else
		{
			/* deklaracja zmiennych pomocniczych */
			int index;
			bool exists;
			std::string input;

			Student* student;

			switch (option) // switch na podstawie numeru operacji
			{
			case 1:
				this->getWindow()->setActivePage(4); // przejscie do strony dodawania nowego studenta
				break;

			case 2:
				this->getWindow()->refresh(); // odswiezenie okna
				std::cout << "Podaj nr indeksu studenta, ktorego chcesz usunac: " << std::endl;
				std::cin >> index; // wczytanie indeksu studenta do usuniecia

				if (!std::cin.good())
				{
					std::cout << "indeks to liczba! " << std::endl;
					Sleep(1000);
					break;
				}

				student = (Student*)this->studentList.getObjectByIndex(index); // ustawienie wskaznika na obiekt typu Student o podanym indeksie

				if (!student)
					std::cout << "Nie ma takiego studenta" << std::endl;
				else
				{
					this->lessonList->removeStudentFromLessons(student); // usuniecie studenta z zajec na ktore potencjalnie byl zapisany
					index = this->studentList.removeObject(student->getIndex()); // proba usuniecia studenta z listy studentow
					std::cout << std::endl << "Usunieto studenta o indeksie " << index;
					//delete student;
				}
				
				Sleep(2000);

				break;

			case 3:
				std::cout << "Podaj nr indeksu studenta, ktorego dane chcesz zobaczyc: " << std::endl;
				std::cin >> index; // wczytanie indeksu studenta

				if (!std::cin.good())
				{
					std::cout << "indeks to liczba! " << std::endl;
					Sleep(1000);
					break;
				}

				exists = (Student*)this->studentList.showByIndex(index); // proba wyswietlenia studenta o podanym indeksie

				if (!exists) // jesli student o podanym indeksie nie istnieje to wyswietl komunikat
					std::cout << std::endl << "Nie ma takiego studenta" << std::endl;

				Sleep(2500);
				break;

			case 4:
				std::cout << "Podaj nazwe kierunku studiow" << std::endl;
				std::cin >> input; // wczytanie nazwy kierunku studiow

				// show header

				exists = this->studentList.showByField(input); // proba wyswietlenia studentow z danego kierunku studiow

				if (!exists) // sprawdzenie czy na danym kierunku sa jacys studenci, jesli nie to wyswietl komunikat
				{
					this->getWindow()->refresh(); // odswiezenie okna
					std::cout << std::endl << "Nie ma studentow na tym kierunku" << std::endl;
				}

				Sleep(2500);
				break;

			case 5:
				exists = this->studentList.showByType("stacjonarne"); // proba wyswietlenia studentow stacjonarnych

				if (!exists) // sprawdzenie czy sa jacys studenci stacjonarni, jesli nie to wyswietl komunikat
				{
					this->getWindow()->refresh(); // odswiezenie okna
					std::cout << std::endl << "Nie studentow stacjonarnych" << std::endl;
				}

				Sleep(2500);
				break;

			case 6:
				exists = this->studentList.showByType("zaoczne"); // proba wyswietlenia studentow zaocznych

				if (!exists) // sprawdzenie czy sa jacys studenci zaoczni, jesli nie to wyswietl komunikat
				{
					this->getWindow()->refresh(); // odswiezenie okna
					std::cout << std::endl << "Nie studentow zaocznych" << std::endl;
				}

				Sleep(2500);
				break;

			case 7:
				this->getWindow()->setActivePage(5); // przejscie do strony wyswietlajacej liste studentow
				break;

			case 8:
				std::cout << "Liczba studentow: " << this->studentList.getNumberOfObjects() << std::endl;
				Sleep(2000);
				break;

			case 9:
				std::cout << "Podaj nr indeksu studenta, ktorego chcesz przypisac: " << std::endl;
				std::cin >> index; // wczytanie indeksu

				student = (Student*)this->studentList.getObjectByIndex(index); // ustawienie wskaznika na studenta o podanym indeksie

				if (!student) // sprwadzenie czy student o podanym indeksie istnieje
				{
					std::cout << "Nie ma takiego studenta" << std::endl;
					Sleep(1500);
				}		
				else
				{
					Lesson* lesson; // deklaracja wskaznika na obiekt typu Lesson

					std::cout << "Podaj nazwe zajec, do ktorego chcesz zapisac studenta: " << std::endl;
					std::cin >> input; // wczytanie nazwy zajec

					lesson = this->lessonList->getByName(input); // ustawienie wskaznika na obiekt typu Lesson o podanej nazwie

					if (!lesson) // sprawdzenie czy zajecia o podanej nazwie istnieja
					{
						std::cout << "Nie ma takch zajec" << std::endl;
						Sleep(1500);
					}
					else
					{
						bool ok = lesson->addStudent(student); // proba zapisania studenta na zajecia

						if (ok) // sprwadzenie czy student zostal zapisany na zajecia
							std::cout << "Przypisano studenta do zajec";
						else
							std::cout << "Brak wolnych miejsc / Student juz jest przypisany do tych zajec";

						Sleep(1500);
					}
				}
				break;
			}
			this->getWindow()->refresh(); // odswiezenie okna
		}
	} while (true);
}
