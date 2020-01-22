#include "StudentPage.h"

StudentPage::StudentPage(Window* window) : MainPage(window, "     STUDENCI-SERWIS ")
{
	/* Dodawanie elementow do menu */
	this->menu.addMenuElement("Dodaj studenta");
	this->menu.addMenuElement("Usun studenta");
	this->menu.addMenuElement("Znajdz studenta wedlug indeksu");
	this->menu.addMenuElement("Wyswietl studentow z wydzialu");
	this->menu.addMenuElement("Wyswietl studentow z kierunku");
	this->menu.addMenuElement("Wyswietl studentow stacjonarnych / zaocznych");
	this->menu.addMenuElement("Wyswietl wszystkich studentow");
	this->menu.addMenuElement("Wyswietl liczbe studentow");
	this->menu.addMenuElement("Zapisz studenta na zajecia");

	this->menu.addMenuBackElement("Powrot do strony glownej");

	this->setMenu(&this->menu); // ustawienie menu dla strony
}

StudentPage::StudentPage(const StudentPage& model)
{
	this->menu = model.menu;
	this->studentList = model.studentList;
	this->lessonList = model.lessonList;
}

StudentPage& StudentPage::operator = (const StudentPage& model)
{
	this->menu = model.menu;
	this->studentList = model.studentList;
	this->lessonList = model.lessonList;

	return *this;
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

	SetConsoleTextAttribute(this->getWindow()->getConsole(), 13); // zmiana koloru tekstu w konsoli na rozowy

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

				this->studentList.showByIndex(index); // wyswietlenie danych studenta o podanym indeksie

				Sleep(2500);
				break;

			case 4:
				std::cout << "Podaj nazwe wydzialu studiow (budownictwa | chemiczny | informatyki | matematyki | mechaniczny | zarzadzania)" << std::endl;
				std::cin >> input; // wczytanie nazwy kierunku studiow


				if (input != "budownictwa" && input != "chemiczny" && input != "informatyki" && input != "matematyki" && input != "mechaniczny" && input != "zarzadzania")
					std::cout << "Nie ma takiego wydzialu" << std::endl;
				else
					this->studentList.showByDepartment(input);

				// show header

				Sleep(2500);
				break;
			case 5:
				std::cout << "Podaj nazwe kierunku studiow" << std::endl;
				std::cin >> input; // wczytanie nazwy kierunku studiow

				if(input != "architektura" && input != "biogospodarka" && input != "biotechnologia" 
					&& input != "elektrotechnika" && input != "informatyka" && input != "matematyka" 
					&& input != "fizyka" && input != "logistyka" && input != "zarzadzanie")
					std::cout << "Nie ma takiego kierunku" << std::endl;
				else
					this->studentList.showByField(input); // wyswietlenie studentow z danego kierunku studiow

				Sleep(2500);
				break;

			case 6:
				std::cout << "Podaj tryb studiow (stacjonarne | zaoczne)";
				std::cin >> input;
				while (!std::cin.good() || (input != "stacjonarne" && input != "zaoczne"))
				{
					input.clear();
					this->getWindow()->refresh();
					std::cout << "Podaj tryb studiow (stacjonarne | zaoczne)";
					std::cin.clear();
					std::cin >> input;
				}

				this->studentList.showByType(input); // wyswietlenie studentow danego trybu

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

				if (!student) // sprawdzenie czy student o podanym indeksie istnieje
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
						std::cout << "Podaj typ zajec, do ktorego chcesz zapisac studenta: " << std::endl;
						std::cin >> input; // wczytanie typu zajec

						if (lesson->getType() != input)
						{
							std::cout << "Nie ma takich zajec" << std::endl;
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
				}
				break;
			}
			this->getWindow()->refresh(); // odswiezenie okna
		}
	} while (true);
}
