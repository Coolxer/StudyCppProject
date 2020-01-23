#include "AddLessonPage.h"
#include <iostream>
#include "CmdManager.h"

#include "Lesson.h"

AddLessonPage::AddLessonPage(Window* window) : AddPage(window)
{
	this->header = TextBox('#', "##          Dodawanie zajec           ##"); // stworzenie naglowka
}

AddLessonPage::AddLessonPage(const AddLessonPage& model)
{
	this->header = model.header;
}

AddLessonPage& AddLessonPage::operator = (const AddLessonPage& model)
{
	this->header = model.header;

	return *this;
}

AddLessonPage::~AddLessonPage()
{
	
}

void AddLessonPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN); // ustawienie koloru tekstu w konsoli na zielony
	this->header.show(); 

	this->drawParagraph("Typ:                 | "); // wyswietlenie paragrafu dot. typu
	std::cout << this->strings[0] << std::endl; // wyswietlenie aktualnego typu, jesli nie wpisany to ""

	this->drawParagraph("Name:                | ");
	std::cout << this->strings[1] << std::endl;

	this->drawParagraph("Godzina rozpoczecia: | ");
	this->checkNumber(this->numbers[0]); // sprawdzenie czy numer jest rowny 0 (jeszcze nie wpisany) to wyswietla "", inaczej wyswietla numer

	this->drawParagraph("Czas trwania:        | ");
	this->checkNumber(this->numbers[1]);

	this->drawParagraph("Max. ilosc miejsc    | ");
	this->checkNumber(this->numbers[2]);

	std::cout << std::endl;
}

void AddLessonPage::service()
{
	switch (this->currentStep) // switch na podstawie aktualnego kroku dodawania nowych zajec
	{
	case 1:
		std::cout << "Podaj typ: (wyklad | cwiczenia | laboratorium | projekt)" << std::endl;
		std::cin >> this->strings[0]; // pobranie od uzytkownika typu zajec
		// dopoki wprowadzone dane sa niepoprawne kontynuje prosbe o podanie typu zajec
		while (!std::cin.good() || (this->strings[0] != "wyklad" && this->strings[0] != "cwiczenia" && this->strings[0] != "laboratorium" && this->strings[0] != "projekt"))
		{
			this->strings[0].clear(); // wyczyszczenie napisu
			this->getWindow()->refresh(); // odwswiezenie strony
			std::cout << "Podaj typ: (wyklad | cwiczenia | laboratorium | projekt)" << std::endl;
			std::cin.clear(); // wyczyszczenie wejscia
			std::cin >> this->strings[0]; // pobranie od uzytkownika typu zajec
		}
		break;
	case 2:
		this->testString("Podaj nazwe: (min. 3 litery)", 1); // pobranie odpowiedniej nazwy zajec (pobranie + walidacja)
		break;
	case 3:
		this->testNumber("Podaj godzine rozpoczecia: (min 8 max 18, tylko pelne godziny)", 0, 8, 18); // pobranie odpowiedniej godziny rozpoczecia zajec (pobranie + walidacja)
		break;
	case 4:
		this->testNumber("Podaj czas trwania: (min 120, max 240 [w min.])", 1, 120, 240); // pobranie odpowiedniego czasu trwania zajec (pobranie + walidacja)
		break;
	case 5:
		if (this->strings[0] == "wyklad")
		{
			std::cout << "Podaj max. ilosc miejsc: (min 30, max 100)" << std::endl;
			std::cin >> this->numbers[2];
			
			while (!std::cin.good() || this->numbers[2] < 30 && this->numbers[2] > 100)
			{
				this->strings[0].clear(); // wyczyszczenie napisu
				this->getWindow()->refresh(); // odwswiezenie strony
				std::cout << "Podaj max. ilosc miejsc: (min 30, max 100)" << std::endl;
				std::cin.clear(); // wyczyszczenie wejscia
				std::cin >> this->numbers[2]; // pobranie od uzytkownika typu zajec
			}
		}
		else if (this->strings[0] == "cwiczenia")
		{
			std::cout << "Podaj max. ilosc miejsc: (min 10, max 30)" << std::endl;
			std::cin >> this->numbers[2];

			while (!std::cin.good() || this->numbers[2] < 10 && this->numbers[2] > 30)
			{
				this->strings[0].clear(); // wyczyszczenie napisu
				this->getWindow()->refresh(); // odwswiezenie strony
				std::cout << "Podaj max. ilosc miejsc: (min 10, max 30)" << std::endl;
				std::cin.clear(); // wyczyszczenie wejscia
				std::cin >> this->numbers[2]; // pobranie od uzytkownika typu zajec
			}
		}
		else
		{
			std::cout << "Podaj max. ilosc miejsc: (min 5, max 15)" << std::endl;
			std::cin >> this->numbers[2];

			while (!std::cin.good() || this->numbers[2] < 5 && this->numbers[2] > 15)
			{
				this->strings[0].clear(); // wyczyszczenie napisu
				this->getWindow()->refresh(); // odwswiezenie strony
				std::cout << "Podaj max. ilosc miejsc: (min 5, max 15)" << std::endl;
				std::cin.clear(); // wyczyszczenie wejscia
				std::cin >> this->numbers[2]; // pobranie od uzytkownika typu zajec
			}
		}
		break;
	default:
		// dodanie nowych zajec do listy zajec
		int id = this->objectList->addObject(new Lesson(this->strings[0], this->strings[1], this->numbers[0], this->numbers[1], this->numbers[2]));

		this->getWindow()->refresh();

		if (id == -1)
		{
			SetConsoleTextAttribute(this->getWindow()->getConsole(), 12);
			std::cout << "Podane zajecia juz istnieja" << std::endl << std::endl;
			SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
		}	
		else
		{
			SetConsoleTextAttribute(this->getWindow()->getConsole(), 10);
			std::cout << "Dodano nowe zajecia o id " << id << std::endl << std::endl;
			SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
		}

		Sleep(2000);

		this->resetValues(); // zresetowanie wszystkich wpisywanych wartosci
		this->getWindow()->setActivePage(3); // powrot do glownej strony zajec
		break;
	}

	this->currentStep++; // zwiekszenie postepu dodawania nowego studenta
	this->getWindow()->refresh(); // odswiezenie strony
	this->service(); // powrot na poczatek metody
}
