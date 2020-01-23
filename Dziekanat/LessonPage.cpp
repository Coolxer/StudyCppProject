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
			Lesson* lesson;
			std::string input, input2;

			switch (option) // switch na podstawie numeru operacji
			{
			case 1:
				this->getWindow()->setActivePage(8); // przejscie do strony dodawania nowych zajec
				break;

			case 2:
				this->getWindow()->refresh(); // odswiezenie okna
				std::cout << "Podaj id zajec, ktore chcesz usunac: " << std::endl;
				std::cin >> id; // wczytanie id zajec do usuniecia

				lesson = (Lesson*)this->lessonList.getObjectByIndex(id);

				if (lesson)
				{
					lesson->removeStaffMember();
					id = this->lessonList.removeObject(id); // usuniecie zajec z listy zajec

					SetConsoleTextAttribute(this->getWindow()->getConsole(), 10);
					std::cout << std::endl << "Usunieto zajecia o id " << id;
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);

				}
				else
				{
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 12);
					std::cout << std::endl << "Nie ma takich zajec" << std::endl;
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
				}
					
				Sleep(2000);

				break;

			case 3:
				std::cout << "Podaj nazwe zajec, ktorych szczegoly chcesz zobaczyc: " << std::endl;
				std::cin >> input; // wczytanie nazwy zajec

				std::cout << "Podaj typ zajec" << std::endl;
				std::cin >> input2; // wczytanie typu zajec

				if (this->lessonList.getLessonByNameAndType(input, input2))
					this->lessonList.showByName(input); // wyswietlenie zajec o podanej nazwie
				else
				{
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 12);
					std::cout << "Nie ma takich zajec" << std::endl;
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
				}
				
				Sleep(2500);
				break;

			case 4:
				std::cout << "Podaj nazwe zajec, ktorych prowdzacego chcesz zobaczyc: " << std::endl;
				std::cin >> input; // wczytanie nazwy zajec

				std::cout << "Podaj typ zajec" << std::endl;
				std::cin >> input2; // wczytanie typu zajec

				lesson = this->lessonList.getLessonByNameAndType(input, input2);

				if (lesson)
				{
					StaffMember* staffMember = lesson->getStaffMember(); // pobranie wskaznika na prowadzacego zajecia

					if (!staffMember) // sprawdzenie czy zajecia nie maja prowadzacego
					{
						SetConsoleTextAttribute(this->getWindow()->getConsole(), 12);
						std::cout << std::endl << "Te zajecia nie maja przypisanego prowadzacego" << std::endl;
						SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
					}
					else
						staffMember->show(true); // jesli zajecia maja prowadzacego to wyswietl jego dane
				}
				else
				{
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 12);
					std::cout << std::endl << "Nie ma takich zajec" << std::endl;
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
				}

				Sleep(2000);
					
				break;

			case 5:
				std::cout << "Podaj nazwe zajec, ktorego uczestnikow chcesz zobaczyc: " << std::endl;
				std::cin >> input; // wczytanie nazwy zajec

				std::cout << "Podaj typ zajec" << std::endl;
				std::cin >> input2; // wczytanie typu zajec

				lesson = this->lessonList.getLessonByNameAndType(input, input2);

				if (lesson)
					lesson->showStudents(); // wyswietlenie studentow zapisanych na zajecia
				else
				{
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 12);
					std::cout << std::endl << "Nie ma takich zajec" << std::endl;
					SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
				}

				Sleep(2500);
				break;

			case 6:
				std::cout << "Podaj typ zajec, ktore chcesz zobaczyc: " << std::endl;
				std::cin >> input; // wczytanie typu zajec

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
