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
			int id = -1;
			Lesson* lesson = nullptr;
			std::string input = "", input2 = "";

			switch (option) // switch na podstawie numeru operacji
			{
			case 1:
				this->getWindow()->setActivePage(8); // przejscie do strony dodawania nowych zajec
				break;

			case 2:
				this->getWindow()->refresh(); // odswiezenie okna
				cout << "Podaj nazwe zajec, ktore chcesz usunac: " << endl;
				cin >> input; // wczytanie nazwy zajec

				cout << endl << "Podaj typ zajec" << endl;
				cin >> input2; // wczytanie typu zajec

				lesson = this->lessonList.getLessonByNameAndType(input, input2);

				if (lesson)
				{
					lesson->removeStaffMember();

					id = this->lessonList.removeObject(lesson->getIndex()); // usuniecie zajec z listy zajec

					onSuccess("Usunieto zajecia o id", id);
				}
				else
					onFailure("Nie ma takich zajec");
	
				Sleep(2000);

				break;

			case 3:
				this->getWindow()->refresh(); // odswiezenie okna
				cout << "Podaj nazwe zajec, ktorych szczegoly chcesz zobaczyc: " << endl;
				cin >> input; // wczytanie nazwy zajec

				cout << endl << "Podaj typ zajec" << endl;
				cin >> input2; // wczytanie typu zajec

				lesson = this->lessonList.getLessonByNameAndType(input, input2);

				if (lesson)
					lesson->show(true); // wyswietlenie zajec o podanej nazwie
				else
					onFailure("Nie ma takich zajec");
				
				Sleep(2500);
				break;

			case 4:
				this->getWindow()->refresh(); // odswiezenie okna
				cout << "Podaj nazwe zajec, ktorych prowdzacego chcesz zobaczyc: " << endl;
				cin >> input; // wczytanie nazwy zajec

				cout << endl << "Podaj typ zajec" << endl;
				cin >> input2; // wczytanie typu zajec

				lesson = this->lessonList.getLessonByNameAndType(input, input2);

				if (lesson)
				{
					StaffMember* staffMember = lesson->getStaffMember(); // pobranie wskaznika na prowadzacego zajecia

					if (!staffMember) // sprawdzenie czy zajecia nie maja prowadzacego
						onFailure("Te zajecia nie maja przypisanego prowadzacego");
					else
						staffMember->show(true); // jesli zajecia maja prowadzacego to wyswietl jego dane
				}
				else
					onFailure("Nie ma takich zajec");

				Sleep(2000);
					
				break;

			case 5:
				this->getWindow()->refresh(); // odswiezenie okna
				cout << "Podaj nazwe zajec, ktorego uczestnikow chcesz zobaczyc: " << endl;
				cin >> input; // wczytanie nazwy zajec

				cout << endl << "Podaj typ zajec" << endl;
				cin >> input2; // wczytanie typu zajec

				lesson = this->lessonList.getLessonByNameAndType(input, input2);

				if (lesson)
					lesson->showStudents(); // wyswietlenie studentow zapisanych na zajecia
				else
					onFailure("Nie ma takich zajec");
			
				Sleep(2500);
				break;

			case 6:
				this->getWindow()->refresh(); // odswiezenie okna
				cout << "Podaj typ zajec, ktore chcesz zobaczyc: " << endl;
				cin >> input; // wczytanie typu zajec

				this->lessonList.showSpecificType(input); // wyswietlenie zajec o podanym typie

				Sleep(2500);
				break;

			case 7:
				this->getWindow()->setActivePage(9); // przejscie do strony wyswietlajacej liste zajec
				break;

			case 8:
				this->getWindow()->refresh(); // odswiezenie okna
				cout << "Liczba zajec: " << this->lessonList.getNumberOfObjects() << endl;
				Sleep(2000);
				break;
			}

			this->getWindow()->refresh(); // odswiezenie okna
		}
	} while (true);
}
