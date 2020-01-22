#include "LessonPage.h"

#include "LessonList.h"
#include "StaffMember.h"

LessonPage::LessonPage(Window* window) : MainPage(window, "            ZAJECIA-SERWIS ")
{
	/* Dodawanie elementow do menu */
	this->menu.addMenuElement("Dodaj zajecia");
	this->menu.addMenuElement("Usun zajecia");
	this->menu.addMenuElement("Znajdz zajecia wedlug nazwy");
	this->menu.addMenuElement("Wyswietl prowadzacego zajecia");
	this->menu.addMenuElement("Wyswietl uczestnikow zajec");
	this->menu.addMenuElement("Wyswietl konkretny typ zajec");
	this->menu.addMenuElement("Wyswietl wszystkie zajecia");
	this->menu.addMenuElement("Wyswietl liczbe zajec");

	this->menu.addMenuBackElement("Powrot do strony glownej");

	this->setMenu(&this->menu); // ustawienie menu dla strony
}

LessonPage::LessonPage(const LessonPage& model)
{
	this->menu = model.menu;
	this->lessonList = model.lessonList;
}

LessonPage& LessonPage::operator = (const LessonPage& model)
{
	this->menu = model.menu;
	this->lessonList = model.lessonList;

	return *this;
}

LessonPage::~LessonPage()
{
	
}

LessonList* LessonPage::getLessonList()
{
	return &this->lessonList;
}

void LessonPage::service()
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
			int id;
			bool exists;
			Lesson* lesson;
			std::string input;

			switch (option) // switch na podstawie numeru operacji
			{
			case 1:
				this->getWindow()->setActivePage(8); // przejscie do strony dodawania nowych zajec
				break;

			case 2:
				this->getWindow()->refresh(); // odswiezenie okna
				std::cout << "Podaj id zajec, ktore chcesz usunac: " << std::endl;
				std::cin >> id; // wczytanie id zajec do usuniecia

				id = this->lessonList.removeObject(id); // proba usuniecia zajec z listy zajec

				if (id == -1) // sprawdzenie czy udalo sie usunac zajecia, jesli warunek jest spelniony to nie, inaczej usunieto zajecia 
					std::cout << std::endl << "Nie ma takiego zajecia" << std::endl;
				else
					std::cout << std::endl << "Usunieto zajecie o id " << id;

				Sleep(2000);

				break;

			case 3:
				std::cout << "Podaj nazwe zajecia, ktorego szczegoly chcesz zobaczyc: " << std::endl;
				std::cin >> input; // wczytanie nazwy zajec

				this->lessonList.showByName(input); // wyswietlenie zajec o podanej nazwie

				Sleep(2500);
				break;

			case 4:
				std::cout << "Podaj nazwe zajecia, ktorego prowadzacego chcesz zobaczyc: " << std::endl;
				std::cin >> input; // wczytanie nazwy zajec

				lesson = this->lessonList.getByName(input); // pobranie wskaznika do zajec o podanej nazwie

				if (!lesson) // jesli wskaznik jest pusty to nie ma takich zajec, inaczej ...
					std::cout << std::endl << "Nie ma takich zajec" << std::endl;
				else
				{
					StaffMember* staffMember = lesson->getStaffMember(); // pobranie wskaznika na prowadzacego zajecia

					if (!staffMember) // sprawdzenie czy zajecia nie maja prowadzacego
						std::cout << std::endl << "To zajecie nie ma przypisanego prowadzacego" << std::endl;
					else
						staffMember->show(true); // jesli zajecia maja prowadzacego to wyswietl jego dane
				}

				Sleep(2000);
					
				break;

			case 5:
				std::cout << "Podaj nazwe zajecia, ktorego uczestnikow chcesz zobaczyc: " << std::endl;
				std::cin >> input; // wczytanie nazwy zajec

				lesson = this->lessonList.getByName(input); // pobranie wskaznika do zajec o podanej nazwie

				if (!lesson) // jesli wskaznik jest pusty to nie ma takich zajec, inaczej ...
					std::cout << std::endl << "Nie ma takich zajec" << std::endl;
				else
					lesson->showStudents(); // wyswietlenie studentow zapisanych na zajecia

				Sleep(2500);
				break;

			case 6:
				std::cout << "Podaj typ zajec, ktore chcesz zobaczyc: " << std::endl;
				std::cin >> input; // wczytanie typu zajec

				//Lesson::showHeader();

				this->lessonList.showSpecificType(input); // wyswietlenie zajec o podanym typie

				Sleep(2500);
				break;

			case 7:
				this->getWindow()->setActivePage(9); // przejscie do strony wyswietlajacej liste zajec
				break;

			case 8:
				std::cout << "Liczba zajec: " << this->lessonList.getNumberOfObjects() << std::endl;
				Sleep(2000);
				break;
			}

			this->getWindow()->refresh(); // odswiezenie okna
		}
	} while (true);
}
