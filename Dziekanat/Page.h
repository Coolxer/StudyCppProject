#pragma once
#include "windows.h"
#include "Window.h"

#include <iostream>
#include "CmdManager.h"

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
	~Page(); // destruktor

	Window* getWindow(); // metoda zwraca wskaznik na obiekt klasy Window

	virtual void draw() = 0; // metoda czysto wirtualna (bez definicji) -> musi byc przeslonieta w klasie potomnej 
	virtual void service() = 0; // metoda czysto wirtualna (bez definicji) -> musi byc przeslonieta w klasie potomnej
};

