#pragma once
#include "windows.h"

/* Klasa reprezentujaca okno programu */

class Page; // deklaracja klasy Page

class Window
{
private:
	HANDLE console; // konsola
	Page* pages[10]; // tablica wskaznikow na obiekty klasy Page

	int activePageIndex; // numer aktualnej strony

	void clear(); // metoda czysci ekran
	void drawActivePage(); // metoda wyswietla aktualna strone
public:
	Window(); // konstruktor domyslny
	~Window(); // destruktor

	void refresh(); // metoda odswieza okno

	void setActivePage(int pageIndex); // metoda ustawia aktualna strone
	HANDLE getConsole(); // metoda zwraca obiekt typu HANDLE
};

