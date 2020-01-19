#include "AddStudentPage.h"
#include <iostream>
#include "CmdManager.h"

#include "Student.h"

AddStudentPage::AddStudentPage(Window* window) : AddPage(window)
{
	this->header = TextBox('#', "##   Dodawanie studenta   ##");
}

AddStudentPage::~AddStudentPage()
{

}

void AddStudentPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	this->drawParagraph("Imie:     | "); // wyswietlenie paragrafu dot. imienia
	std::cout << this->strings[0] << std::endl; // wyswietlenie aktualnego imienia, jesli nie wpisane to ""

	this->drawParagraph("Nazwisko: | ");
	std::cout << this->strings[1] << std::endl;

	this->drawParagraph("Wiek:     | ");
	this->checkNumber(this->numbers[0]); // sprawdzenie czy numer jest rowny 0 (jeszcze nie wpisany) to wyswietla "", inaczej wyswietla numer

	this->drawParagraph("Kierunek: | ");
	std::cout << this->strings[2] << std::endl;

	this->drawParagraph("Stopien:  | ");
	this->checkNumber(this->numbers[1]);

	this->drawParagraph("Rok:      | ");
	this->checkNumber(this->numbers[2]);

	this->drawParagraph("Typ:      | ");
	std::cout << this->strings[3] << std::endl;

	std::cout << std::endl;
}

void AddStudentPage::service()
{
	switch (this->currentStep) // switch na podstawie aktualnego kroku dodawania nowego studenta
	{
	case 1:
		this->testString("Podaj imie: (min. 3 litery)", 0); // pobranie odpowiedniego imienia studenta (pobranie + walidacja)
		break;
	case 2:
		this->testString("Podaj nazwisko: (min. 3 litery)", 1); // pobranie odpowiedniego nazwiska studenta (pobranie + walidacja)
		break;
	case 3:
		this->testNumber("Podaj wiek: (min. 20, max. 100)", 0, 20, 100); // pobranie odpowiedniego wieku studenta (pobranie + walidacja)
		break;
	case 4:
		this->testString("Podaj kierunek: (min. 3 litery)", 2); // pobranie odpowiedniego kierunku studiow (pobranie + walidacja)
		break;
	case 5:
		this->testNumber("Podaj stopien: (1 lub 2)", 1, 1, 2); // pobranie odpowiedniego stopnia studiow (pobranie + walidacja)
		break;
	case 6:
		this->testNumber("Podaj rok: (1 - 4)", 2, 1, 4); // pobranie odpowiedniego roku studiow (pobranie + walidacja)
		break;
	case 7:
		std::cout << "Podaj typ: (stacjonarne lub zaoczne)" << std::endl;
		std::cin >> this->strings[3];
		// dopoki wprowadzone dane sa niepoprawne kontynuje prosbe o podanie odpowiedniego trybu studiow
		while (!std::cin.good() || (this->strings[3] != "stacjonarne" && this->strings[3] != "zaoczne"))
		{
			this->strings[3].clear();
			this->getWindow()->refresh();
			std::cout << "Podaj typ: (stacjonarne lub zaoczne)" << std::endl;
			std::cin.clear();
			std::cin >> this->strings[3];
		}
		break;
	default:
		// dodanie nowego studenta do listy studentow
		int index = this->objectList->addObject(new Student(this->strings[0], this->strings[1], this->numbers[0], this->strings[2], this->numbers[1], this->numbers[2], this->strings[3]));

		this->getWindow()->refresh();
		std::cout << "Dodano nowego studenta o indeksie " << index << std::endl << std::endl;

		Sleep(2000);

		this->resetValues(); // zresetowanie wszystkich wpisywanych wartosci
		this->getWindow()->setActivePage(1); // powrot do glownej strony studentow
		break;
	}

	this->currentStep++; // zwiekszenie postepu dodawania nowego studenta
	this->getWindow()->refresh(); // odswiezenie strony
	this->service(); // powrot na poczatek metody
}
