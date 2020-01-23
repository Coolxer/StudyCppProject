#include "StaffPage.h"

StaffPage::StaffPage(Window* window) : MainPage(window, "      GRONO PEDAGOGICZNE-SERWIS ")
{
	/* Dodawanie elementow do menu */
	this->menu.addMenuElement("Dodaj pracownika");
	this->menu.addMenuElement("Usun pracownika");
	this->menu.addMenuElement("Znajdz pracownika wedlug id");
	this->menu.addMenuElement("Wyswietl profesorow");
	this->menu.addMenuElement("Wyswietl wszystkich pracownikow");
	this->menu.addMenuElement("Wyswietl liczbe pracownikow");
	this->menu.addMenuElement("Przypisz pracownika do zajec");

	this->menu.addMenuBackElement("Powrot do strony glownej");

	this->setMenu(&this->menu); // ustawienie menu dla strony
}

StaffPage::StaffPage(const StaffPage& model)
{
	this->menu = model.menu;
	this->staffList = model.staffList;
	this->lessonList = model.lessonList;
}

StaffPage& StaffPage::operator = (const StaffPage& model)
{
	this->menu = model.menu;
	this->staffList = model.staffList;
	this->lessonList = model.lessonList;

	return *this;
}

StaffPage::~StaffPage()
{
	//delete this->lessonList;
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
			int id;
			bool exists;
			std::string input, input2;

			StaffMember* staffMember;

			switch (option) // switch na podstawie numeru operacji
			{
			case 1:
				this->getWindow()->setActivePage(6); // przejscie do strony dodawania nowego pracownika
				break;

			case 2:
				this->getWindow()->refresh(); // odswiezenie okna
				std::cout << "Podaj id pracownika, ktorego chcesz zwolnic: " << std::endl;
				std::cin >> id; // wczytanie id pracownika do usuniecia

				staffMember = (StaffMember*)this->staffList.getObjectByIndex(id); // ustawienie wskaznika na obiekt typu StaffMember o podanym id

				exists = this->staffList.removeObject(staffMember->getIndex()); // proba usuniecia pracownika o podanym id z listy

				if (!exists) // jesli pracownik o podanym id nie istnieje to wyswietl komunikat
				{
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 12);
					std::cout << std::endl << "Nie ma takiego pracownika" << std::endl;
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
				}	
				else
				{
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 10);
					std::cout << std::endl << "Usunieto pracownika o indeksie " << id;
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
					this->lessonList->removeStaffMemberFromLessons(staffMember); // usuniecie pracownika z zajec ktorych jest prowadzacym
				}
					
				Sleep(2000);

				break;

			case 3:
				this->getWindow()->refresh(); // odswiezenie okna
				std::cout << "Podaj id pracownika, ktorego dane chcesz zobaczyc: " << std::endl;
				std::cin >> id; // wczytanie id pracownika
	
				this->staffList.showByIndex(id); // wyswietlenia danych pracownika o podanym id

				Sleep(2500);
				break;

			case 4:
				this->getWindow()->refresh(); // odswiezenie okna
				this->staffList.showProfessors(); // wyswietlenie profesorow

				Sleep(2500);
				break;

			case 5:
				this->getWindow()->setActivePage(7); // przejscie do strony wyswietlajacej liste pracownikow
				break;	

			case 6:
				this->getWindow()->refresh(); // odswiezenie okna
				std::cout << "Liczba pracownikow: " << this->staffList.getNumberOfObjects() << std::endl;
				Sleep(2000);
				break;
			case 7:
				this->getWindow()->refresh(); // odswiezenie okna
				std::cout << "Podaj nr id pracownika, ktorego chcesz przypisac: " << std::endl;
				std::cin >> id;

				staffMember = (StaffMember*)this->staffList.getObjectByIndex(id); // ustawienie wskaznika na obiekt typu StaffMember o podanym id

				if (!staffMember) // sprawdzenie czy pracownik o podanym id istnieje, jesli nie to wyswietl komunikat
				{
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 12);
					std::cout << std::endl << "Nie ma takiego pracownika" << std::endl;
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
					Sleep(1500);
				}
				else
				{
					Lesson* lesson;

					std::cout << std::endl << "Podaj nazwe zajec, do ktorych chcesz przypisac prowadzacego: " << std::endl;
					std::cin >> input; // wczytanie nazwy zajec

					std::cout << std::endl << "Podaj typ zajec (wyklad | cwiczenia | laboratorium | projekt)" << std::endl;
					std::cin >> input2; // wczytanie typu zajec

					lesson = this->lessonList->getLessonByNameAndType(input, input2);

					if (!lesson)
					{
						SetConsoleTextAttribute(this->getWindow()->getConsole(), 12);
						std::cout << "Nie ma takich zajec" << std::endl;
						SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
						Sleep(1500);
					}
					else
					{
						bool ok = lesson->setStaffMember(staffMember); // przypisanie prowadzacego do zajec

						if (ok) // jesli podany prowa
						{
							SetConsoleTextAttribute(this->getWindow()->getConsole(), 10);
							std::cout << std::endl << "Przypisano pracownika do zajec";
							SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
							staffMember->increaseLessons();
						}
						else
						{
							SetConsoleTextAttribute(this->getWindow()->getConsole(), 12);
							std::cout << std::endl << "To zajecie ma juz swojego prowadzacego";
							SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
						}

						Sleep(1500);
					}
				}
				break;
			}	
			this->getWindow()->refresh();
		}
	} while (true);
}
