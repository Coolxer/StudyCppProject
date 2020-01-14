#pragma once
#include "AddPage.h"

/* Klasa reprezentujaca strone sluzaca do dodawania nowych zajec */
/* Klasa dziedziczy (rozszerza) klase AddPage */

class AddLessonPage: public AddPage
{
private:
	TextBox header; // naglowek strony
public:
	AddLessonPage(Window* window); // konstruktor z argumentem wskaünika do obiektu klasy Window
	~AddLessonPage(); // destruktor

	void draw(); // metoda rysuje strone
	void service(); // metoda zarzadza operacjami na stronie
};

