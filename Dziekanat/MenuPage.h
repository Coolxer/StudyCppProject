#pragma once
#include "MainPage.h"

/* Klasa reprezentujaca glowna strone */
/* Klasa dziedziczy (rozszerza) klase MainPage */

class MenuPage : public MainPage
{
private:
	Menu menu; // menu nawigacyjne

public:
	MenuPage(Window* window = nullptr); // konstruktor domyslny z argumentem wskaünika do obiektu klasy Window
	MenuPage(const MenuPage& model); // konstruktor kopiujacy
	MenuPage& operator = (const MenuPage& model); // przeciazenie operatora przypisania
	~MenuPage(); // destruktor

	void service();  // metoda zarzadza operacjami na stronie
};

