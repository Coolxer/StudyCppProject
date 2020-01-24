#pragma once
#include <iostream>
#include <string>
#include "windows.h"

#include "Window.h"
#include "CmdManager.h"

using namespace std;

/* Klasa reprezentujaca strone ( wyglad + logika ) */
/* Klasa stanowi baze do stron typu AddPage i MainPage*/
/* Nie mozna utworzyc obiektow tej klasy, bo jest ona abstrakcyjna */
/* Klasa posiada 2 metody czysto wirtualne: draw() i service() */
/* Metody te musza byc przesloniete w klasach potomnych, inaczej kompilator zwroci blad*/

class Page
{
private:
	Window* window; // wskaznik na obiekt klasy Window
public:
	Page(Window* window = nullptr); // konstruktor domyslny z argumentem wskaŸnika do obiektu klasy Window
	Page(const Page& model); // konstruktor kopiujacy
	Page& operator = (const Page& model); // przeciazenie operatora przypisania
	~Page(); // destruktor

	Window* getWindow(); // metoda zwraca wskaznik na obiekt klasy Window

	void onSuccess(string str, int value=-1); // wyswietla komunikat w kolorze zielonym
	void onFailure(string str); // wyswietla komunikat w kolorze czerwonym

	virtual void draw() = 0; // metoda czysto wirtualna (bez definicji) -> musi byc przeslonieta w klasie potomnej 
	virtual void service() = 0; // metoda czysto wirtualna (bez definicji) -> musi byc przeslonieta w klasie potomnej
};

