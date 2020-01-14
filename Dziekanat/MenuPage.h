#pragma once
#include "MainPage.h"

/* Klasa reprezentujaca glowna strone */
/* Klasa dziedziczy (rozszerza) klase MainPage */

class MenuPage : public MainPage
{
private:
	Menu menu; // menu nawigacyjne

public:
	MenuPage(Window* window); // konstruktor z argumentem wskaünika do obiektu klasy Window
	~MenuPage(); // destruktor

	void service();  // metoda zarzadza operacjami na stronie
};

