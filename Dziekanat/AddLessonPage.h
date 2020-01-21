#pragma once
#include "AddPage.h"

/* Klasa reprezentujaca strone sluzaca do dodawania nowych zajec */
/* Klasa dziedziczy (rozszerza) klase AddPage */

class AddLessonPage: public AddPage
{
private:
	TextBox header; // naglowek strony
public:
	AddLessonPage(Window* window = nullptr); // konstruktor domyslny z argumentem wskaünika do obiektu klasy Window
	AddLessonPage(const AddLessonPage& model); // konstruktor kopiujacy
	AddLessonPage& operator = (const AddLessonPage& model); // przeciazenie operatora przypisania
	~AddLessonPage(); // destruktor

	void draw(); // metoda rysuje strone
	void service(); // metoda zarzadza operacjami na stronie
};

