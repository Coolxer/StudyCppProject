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

	this->lessonList = nullptr;

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
			int id = -1;
			std::string input = "", input2 = "";

			StaffMember* staffMember = nullptr;

			switch (option) // switch na podstawie numeru operacji
			{
			case 1:
				this->getWindow()->setActivePage(6); // przejscie do strony dodawania nowego pracownika
				break;

			case 2:
				this->getWindow()->refresh(); // odswiezenie okna
				cout << "Podaj id pracownika, ktorego chcesz zwolnic: " << endl;
				cin >> id; // wczytanie id pracownika do usuniecia

				staffMember = (StaffMember*)this->staffList.getObjectByIndex(id); // ustawienie wskaznika na obiekt typu StaffMember o podanym id

				id = this->staffList.removeObject(id); // proba usuniecia pracownika o podanym id z listy

				if (id == -1) // jesli pracownik o podanym id nie istnieje to wyswietl komunikat
					onFailure("Nie ma takiego pracownika");
				else
				{
					this->lessonList->removeStaffMemberFromLessons(staffMember); // usuniecie pracownika z zajec ktorych jest prowadzacym
					onSuccess("Usunieto pracownika o id", id);
				}
					
				Sleep(2000);

				break;

			case 3:
				this->getWindow()->refresh(); // odswiezenie okna
				cout << "Podaj id pracownika, ktorego dane chcesz zobaczyc: " << endl;
				cin >> id; // wczytanie id pracownika
	
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
				cout << "Liczba pracownikow: " << this->staffList.getNumberOfObjects() << endl;
				Sleep(2000);
				break;

			case 7:
				this->getWindow()->refresh(); // odswiezenie okna
				cout << "Podaj nr id pracownika, ktorego chcesz przypisac: " << endl;
				cin >> id;

				staffMember = (StaffMember*)this->staffList.getObjectByIndex(id); // ustawienie wskaznika na obiekt typu StaffMember o podanym id

				if (!staffMember) // sprawdzenie czy pracownik o podanym id istnieje, jesli nie to wyswietl komunikat
					onFailure("Nie ma takiego pracownika");
				else
				{
					Lesson* lesson = nullptr;

					cout << endl << "Podaj nazwe zajec, do ktorych chcesz przypisac prowadzacego: " << endl;
					cin >> input; // wczytanie nazwy zajec

					cout << endl << "Podaj typ zajec (wyklad | cwiczenia | laboratorium | projekt)" << endl;
					cin >> input2; // wczytanie typu zajec

					lesson = this->lessonList->getLessonByNameAndType(input, input2);

					if (!lesson)
						onFailure("Nie ma takich zajec");
					else
					{
						bool ok = lesson->setStaffMember(staffMember); // przypisanie prowadzacego do zajec

						if (ok)
						{
							onSuccess("Przypisano pracownika do zajec");
							staffMember->increaseLessons();
						}
						else
							onFailure("Te zajecia maja juz swojego prowadzacego");
					}
				}
				Sleep(1500);
				break;
			}	
			this->getWindow()->refresh();
		}
	} while (true);
}
