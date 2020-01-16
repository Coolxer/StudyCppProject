#pragma once
#include <string>
#include "Page.h" 
#include "TextBox.h"

#include "ObjectList.h"

/* Klasa sluzaca do dodawania obiektow, bedaca klasa bazowa, ktorych obiektow nie ma w programie */
/* Nie mozna utworzyc obiektow tej klasy, bo jest ona abstrakcyjna */
/* Klasa posiada 2 metody czysto wirtualne: draw() i service() */
/* Metody te musza byc przesloniete w klasach potomnych, inaczej kompilator zwroci blad*/

class AddPage : public Page
{
protected:
	int currentStep; // aktualny krok dodawania nowego obiektu, zainicjalizowany jedynka
	std::string strings[10]; // tablica napisow, sluzaca jako dane tymczasowe
	int numbers[10]; // tablica liczb calkowitych, sluzaca jako dane tymczasowe
	ObjectList* objectList; // wskaznik na obiekt klasy ObjectList
public:
	AddPage(Window* window); // konstruktor z argumentem wskaünika do obiektu klasy Window
	~AddPage(); // destruktor

	void init(ObjectList* objectList); // metoda ustawia wskaznik na obiekt klasy ObjectList

	void resetValues(); // metoda resetuje aktualny krok oraz dane tymczasowe

	void checkNumber(int number); // metoda sprawdza czy podany numer jest rowny 0, jesli tak to wypisuje '', inaczej wypisuje numer
	void testString(std::string text, int id); // metoda sprawdza czy podany napis jest poprawny
	void testNumber(std::string text, int id, int min, int max); // metoda sprawdza czy podana liczba miesci sie w zakresie <min, max>

	void drawParagraph(std::string text); // metoda rysuje paragraf
	
	virtual void draw() = 0; // metoda czysto wirtualna (bez definicji) -> musi byc przeslonieta w klasie potomnej
	virtual void service() = 0; // metoda czysto wirtualna (bez definicji) -> musi byc przeslonieta w klasie potomnej
};

