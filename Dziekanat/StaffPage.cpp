#include "StaffPage.h"

StaffPage::StaffPage(Window* window) : MainPage(window, " GRONO PEDAGOGICZNE SERWIS ")
{
	/* Dodawanie elementow do menu */
	this->menu.addMenuElement("Dodaj pracownika");
	this->menu.addMenuElement("Usun pracownika");
	this->menu.addMenuElement("Znajdz pracownika wedlug id");
	this->menu.addMenuElement("Wyswietl profesorow");
	this->menu.addMenuElement("Wyswietl wszystkich pracownikow");
	this->menu.addMenuElement("Wyswietl liczbe pracownikow");
	this->menu.addMenuElement("Przypisz pracownika do zajec");

	this->setMenu(&this->menu); // ustawienie menu dla strony
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
			continue;
		else
		{
			/* deklaracja zmiennych pomocniczych */
			int id;
			bool exists;
			std::string input;

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

				if (!std::cin.good())
				{
					std::cout << "id to liczba! " << std::endl;
					Sleep(1000);
					break;
				}

				staffMember = (StaffMember*)this->staffList.getObjectByIndex(id); // ustawienie wskaznika na obiekt typu StaffMember o podanym id

				exists = this->staffList.removeObject(staffMember->getIndex()); // proba usuniecia pracownika o podanym id z listy

				if (!exists) // jesli pracownik o podanym id nie istnieje to wyswietl komunikat
					std::cout << std::endl << "Nie ma takiego pracownika" << std::endl;
				else
				{
					std::cout << std::endl << "Usunieto pracownika o indeksie " << id;
					this->lessonList->removeStaffMemberFromLessons(staffMember); // usuniecie pracownika z zajec ktorych jest prowadzacym
				}
					
				Sleep(2000);

				break;
			case 3:
				std::cout << "Podaj id pracownika, ktorego dane chcesz zobaczyæ: " << std::endl;
				std::cin >> id; // wczytanie id pracownika

				if (!std::cin.good())
				{
					std::cout << "id to liczba! " << std::endl;
					Sleep(1000);
					break;
				}

				this->staffList.showByIndex(id); // wyswietlenia danych pracownika o podanym id

				Sleep(2500);
				break;
			case 4:

				//StaffMember::showHeader();

				this->staffList.showProfessors(); // wyswietlenie profesorow

				Sleep(2500);
				break;
			case 5:
				this->getWindow()->setActivePage(7); // przejscie do strony wyswietlajacej liste pracownikow
				break;	
			case 6:
				std::cout << "Liczba pracownikow: " << this->staffList.getNumberOfObjects() << std::endl;
				Sleep(2000);
				break;
			case 7:
				std::cout << "Podaj nr id pracownika, ktorego chcesz przypisac: " << std::endl;
				std::cin >> id;

				staffMember = (StaffMember*)this->staffList.getObjectByIndex(id); // ustawienie wskaznika na obiekt typu StaffMember o podanym id

				if (!staffMember) // sprawdzenie czy pracownik o podanym id istnieje, jesli nie to wyswietl komunikat
				{
					std::cout << "Nie ma takiego pracownika" << std::endl;
					Sleep(1500);
				}
				else
				{
					Lesson* lesson;

					std::cout << "Podaj nazwe zajec, do ktorego chcesz przypisac pracownika: " << std::endl;
					std::cin >> input; // wczytanie nazwy zajec

					lesson = this->lessonList->getByName(input); // ustawienie wskaznika na obiekt typu Lesson o podanej nazwie

					if (!lesson) // sprawdzenie czy zajecia o podanej nazwie istnieja, jesli nie to wyswietl komunikat
					{
						std::cout << "Nie ma takiego zajec" << std::endl;
						Sleep(1500);
					}
					else
					{
						bool ok = lesson->setStaffMember(staffMember); // przypisanie prowadzacego do zajec

						if (ok) // jesli podany prowa
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
