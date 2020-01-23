#include "StudentPage.h"

StudentPage::StudentPage(Window* window) : MainPage(window, "            STUDENCI-SERWIS")
{
	/* Dodawanie elementow do menu */
	this->menu.addMenuElement("Dodaj studenta");
	this->menu.addMenuElement("Usun studenta");
	this->menu.addMenuElement("Znajdz studenta wedlug indeksu");
	this->menu.addMenuElement("Wyswietl studentow z wydzialu");
	this->menu.addMenuElement("Wyswietl studentow z kierunku");
	this->menu.addMenuElement("Wyswietl studentow z trybu");
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

	do {
		option = CmdManager::listen(); // pobranie numeru operacji do wykonania

		if (option == 0)
		{
			this->getWindow()->setActivePage(0); // powrot do strony glownej
			break;
		}
		else if (option == -1)
		{
			Sleep(1000);
			this->getWindow()->refresh();
			continue;
		}
		else
		{
			/* deklaracja zmiennych pomocniczych */
			int index;
			bool exists;
			std::string input, input2;

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

				student = (Student*)this->studentList.getObjectByIndex(index); // ustawienie wskaznika na obiekt typu Student o podanym indeksie

				if (!student)
				{
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 12); // zmiana koloru tekstu w konsoli na czerwony
					std::cout << "Nie ma takiego studenta" << std::endl;
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 15); // zmiana koloru tekstu w konsoli na bialy
				}
				else
				{
					this->lessonList->removeStudentFromLessons(student); // usuniecie studenta z zajec na ktore potencjalnie byl zapisany
					index = this->studentList.removeObject(student->getIndex()); // proba usuniecia studenta z listy studentow
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 10); // zmiana koloru tekstu w konsoli na zielony
					std::cout << std::endl << "Usunieto studenta o indeksie " << index;
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 15); // zmiana koloru tekstu w konsoli na bialy
					//delete student;
				}
				
				Sleep(2000);

				break;

			case 3:
				this->getWindow()->refresh(); // odswiezenie okna
				std::cout << "Podaj nr indeksu studenta, ktorego dane chcesz zobaczyc: " << std::endl;
				std::cin >> index; // wczytanie indeksu studenta
 
				this->studentList.showByIndex(index); // wyswietlenie danych studenta o podanym indeksie

				Sleep(2500);
				break;

			case 4:
				this->getWindow()->refresh(); // odswiezenie okna
				std::cout << "Podaj nazwe wydzialu studiow (budownictwa | chemiczny | informatyki | matematyki | mechaniczny | zarzadzania)" << std::endl;
				std::cin >> input; // wczytanie nazwy kierunku studiow


				if (input != "budownictwa" && input != "chemiczny" && input != "informatyki" && input != "matematyki" && input != "mechaniczny" && input != "zarzadzania")
				{
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 12); 
					std::cout << "Nie ma takiego wydzialu" << std::endl;
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 15); 
				}
					
				else
					this->studentList.showByDepartment(input);

				Sleep(2500);
				break;
			case 5:
				this->getWindow()->refresh(); // odswiezenie okna
				std::cout << "Podaj nazwe kierunku studiow: " << std::endl << "( architektura | biogospodarka | biotechnologia | elektrotechnika | informatyka | matematyka | fizyka | logistyka | zarzadzanie" << std::endl;
				std::cin >> input; // wczytanie nazwy kierunku studiow

				if (input != "architektura" && input != "biogospodarka" && input != "biotechnologia"
					&& input != "elektrotechnika" && input != "informatyka" && input != "matematyka"
					&& input != "fizyka" && input != "logistyka" && input != "zarzadzanie")
				{
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 12);
					std::cout << "Nie ma takiego kierunku" << std::endl;
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
				}
				else
					this->studentList.showByField(input); // wyswietlenie studentow z danego kierunku studiow

				Sleep(2500);
				break;

			case 6:
				this->getWindow()->refresh(); // odswiezenie okna
				std::cout << "Podaj tryb studiow (stacjonarne | zaoczne)" << std::endl;
				std::cin >> input;
				while (!std::cin.good() || (input != "stacjonarne" && input != "zaoczne"))
				{
					input.clear();
					this->getWindow()->refresh();
					std::cout << "Podaj tryb studiow (stacjonarne | zaoczne)" << std::endl;
					std::cin.clear();
					std::cin >> input;
				}

				this->studentList.showByType(input); // wyswietlenie studentow danego trybu

				Sleep(3500);
				break;
			case 7:
				this->getWindow()->setActivePage(5); // przejscie do strony wyswietlajacej liste studentow
				break;

			case 8:
				this->getWindow()->refresh(); // odswiezenie okna
				std::cout << "Liczba studentow: " << this->studentList.getNumberOfObjects() << std::endl;
				Sleep(2000);
				break;

			case 9:
				this->getWindow()->refresh(); // odswiezenie okna
				std::cout << "Podaj nr indeksu studenta, ktorego chcesz przypisac: " << std::endl;
				std::cin >> index; // wczytanie indeksu

				student = (Student*)this->studentList.getObjectByIndex(index); // ustawienie wskaznika na studenta o podanym indeksie

				if (!student) // sprawdzenie czy student o podanym indeksie istnieje
				{
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 12);
					std::cout << "Nie ma takiego studenta" << std::endl;
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
					Sleep(1500);
				}		
				else
				{
					Lesson* lesson; // deklaracja wskaznika na obiekt typu Lesson

					std::cout << std::endl << "Podaj nazwe zajec, do ktorych chcesz zapisac studenta: " << std::endl;
					std::cin >> input; // wczytanie nazwy zajec

					std::cout << std::endl << "Podaj typ zajec (wyklad | cwiczenia | laboratorium | projekt)" << std::endl;
					std::cin >> input2; // wczytanie typu zajec

					lesson = this->lessonList->getLessonByNameAndType(input, input2); // ustawienie wskaznika na obiekt typu Lesson o podanej nazwie

					if (!lesson) // sprawdzenie czy zajecia o podanej nazwie i typie istnieja
					{
						SetConsoleTextAttribute(this->getWindow()->getConsole(), 12);
						std::cout << "Nie ma takich zajec" << std::endl;
						SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
						Sleep(1500);
					}
					else
					{
						bool ok = lesson->addStudent(student); // proba zapisania studenta na zajecia

						if (ok) // sprwadzenie czy student zostal zapisany na zajecia
						{
							SetConsoleTextAttribute(this->getWindow()->getConsole(), 10);
							std::cout << std::endl << "Przypisano studenta do zajec";
							SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
						}
						else
						{
							SetConsoleTextAttribute(this->getWindow()->getConsole(), 12);
							std::cout << std::endl << "Brak wolnych miejsc / Student juz jest przypisany do tych zajec";
							SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
						}
		
						Sleep(1500);
					}
				}
				break;
			}
			this->getWindow()->refresh(); // odswiezenie okna
		}
	} while (true);
}
