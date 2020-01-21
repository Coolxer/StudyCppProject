#include "AddPage.h"
#include <iostream>

#include "CmdManager.h"

AddPage::AddPage(Window* window) : Page(window)
{
	this->resetValues(); // zresetowanie wpisywanych wartosci na starcie
}

AddPage::AddPage(const AddPage& model)
{
	this->currentStep = model.currentStep;
	
	for (int i = 0; i < 10; i++)
	{
		this->strings[i] = model.strings[i];
		this->numbers[i] = model.numbers[i];
	}

	this->objectList = model.objectList;
}

AddPage& AddPage::operator = (const AddPage& model)
{
	this->currentStep = model.currentStep;

	for (int i = 0; i < 10; i++)
	{
		this->strings[i] = model.strings[i];
		this->numbers[i] = model.numbers[i];
	}

	this->objectList = model.objectList;

	return *this;
}

AddPage::~AddPage()
{
	 
}

void AddPage::init(ObjectList* objectList)
{
	this->objectList = objectList; // przypisanie wskaznika na liste obiektow
}

void AddPage::resetValues()
{
	this->currentStep = 1; // ustawienie aktualnego kroku na 1

	for (int i = 0; i < 10; i++)
	{
		this->strings[i].clear(); // wyczyszczenie napisu
		this->numbers[i] = 0; // wyzerowanie liczby
	}
}

void AddPage::checkNumber(int number)
{
	// jesli liczba jest rowna 0, to wypisuje spacje, inaczej wypisuje liczbe
	if (number == 0)
		std::cout << ' ' << std::endl;
	else
		std::cout << number << std::endl;
}

void AddPage::testString(std::string text, int id)
{
	std::cout << text << std::endl; // wyswietlenie informacji, co nalezy wpisac
	std::cin >> this->strings[id]; // pobranie danych od uzytkownika
	// dopoki wprowadzone dane sa nieprawidlowe, program prosi o wpisanie
	while (!std::cin.good() || this->strings[id].length() < 3)
	{
		this->strings[id].clear(); // czyszczenie napisu
		this->getWindow()->refresh(); // odwiezenie okna
		std::cout << text << std::endl; // wyswietlenie informacji, co nalezy wpisac
		std::cin.clear(); // czyszczenie wejscia
		std::cin >> this->strings[id]; // pobranie danych od uzytkownika
	}
}

void AddPage::testNumber(std::string text, int id, int min, int max)
{
	std::cout << text << std::endl; // wyswietlenie informacji, co nalezy wpisac
	std::cin >> this->numbers[id]; // pobranie danych od uzytkownika
	// dopoki wprowadzone dane sa nieprawidlowe, program prosi o wpisanie
	while (!std::cin.good() || this->numbers[id] < min || this->numbers[id] > max)
	{
		this->numbers[id] = 0; // wyzerowanie liczby
		this->getWindow()->refresh(); // odwiezenie okna
		std::cout << text << std::endl; // wyswietlenie informacji, co nalezy wpisac
		std::cin.clear(); // czyszczenie wejscia
		std::cin >> this->numbers[id];// pobranie danych od uzytkownika
	}
}

void AddPage::drawParagraph(std::string text)
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN); // zmiana koloru tekstu w konsoli na zielony
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED); // zmiana koloru tekstu w konsoli na czerwony
	std::cout << text;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15); // zmiana koloru tekstu w konsoli na bialy
}

