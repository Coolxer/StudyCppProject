#pragma once
#include "AddPage.h"

/* Klasa reprezentujaca strone sluzaca do dodawania nowych pracownikow uczelni */
/* Klasa dziedziczy (rozszerza) klase AddPage */

class AddStaffMemberPage : public AddPage
{
private:
	TextBox header; // naglowek strony
public:
	AddStaffMemberPage(Window* window); // konstruktor z argumentem wskaünika do obiektu klasy Window
	~AddStaffMemberPage(); // destruktor

	void draw(); // metoda rysuje strone
	void service(); // metoda zarzadza operacjami na stronie
};

