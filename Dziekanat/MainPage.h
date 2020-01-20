#pragma once
#include "Page.h"
#include "TextBox.h"
#include "ObjectList.h"

#include "Menu.h"

/* Klasa sluzaca nawigacji po programie, bedaca klasa bazowa, ktorych obiektow nie ma w programie */
/* Nie mozna utworzyc obiektow tej klasy, bo jest ona abstrakcyjna */
/* Klasa posiada metode czysto wirtualna: service() */
/* Metoda ta musi byc przesloniete w klasach potomnych, inaczej kompilator zwroci blad */

class MainPage : public Page
{
private:
	TextBox header; // naglowek strony
	Menu menu; // menu nawigacyjne
	TextBox info; // podpowiedz

public:
	MainPage(Window* window = nullptr, std::string headerText = ""); // konstruktor domyslny z 2 argumentami: wskaznikiem na obiekt klasy Window oraz napisem
	~MainPage(); // destruktor

	void setMenu(Menu* menu); // metoda ustawia menu nawigacyjne

	void draw(); // metoda wyswietla strone
	virtual void service() = 0; // metoda czysto wirtualna (bez definicji) -> musi byc przeslonieta w klasie potomnej
};

