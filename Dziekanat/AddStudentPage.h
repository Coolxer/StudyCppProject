#pragma once
#include "AddPage.h"

/* Klasa reprezentujaca strone sluzaca do dodawania nowych zajec */
/* Klasa dziedziczy (rozszerza) klase AddPage */

class AddStudentPage : public AddPage
{
private:
	TextBox header; // naglowek strony
public:
	AddStudentPage(Window* window = nullptr); // konstruktor domyslny z argumentem wskaünika do obiektu klasy Window
	AddStudentPage(const AddStudentPage& model); // konstruktor kopiujacy
	AddStudentPage& operator = (const AddStudentPage& model); // przeciazenie operatora przypisania
	~AddStudentPage(); // destruktor

	void draw(); // metoda rysuje strone
	void service(); // metoda zarzadza operacjami na stronie
};

