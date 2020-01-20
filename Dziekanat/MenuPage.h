#pragma once
#include "MainPage.h"

/* Klasa reprezentujaca glowna strone */
/* Klasa dziedziczy (rozszerza) klase MainPage */

class MenuPage : public MainPage
{
private:
	Menu menu; // menu nawigacyjne

public:
	MenuPage(Window* window = nullptr); // konstruktor domyslny z argumentem wska�nika do obiektu klasy Window
	~MenuPage(); // destruktor

	void service();  // metoda zarzadza operacjami na stronie
};

