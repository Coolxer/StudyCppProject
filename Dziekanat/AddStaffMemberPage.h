#pragma once
#include "AddPage.h"

/* Klasa reprezentujaca strone sluzaca do dodawania nowych pracownikow uczelni */
/* Klasa dziedziczy (rozszerza) klase AddPage */

class AddStaffMemberPage : public AddPage
{
private:
	TextBox header; // naglowek strony
public:
	AddStaffMemberPage(Window* window = nullptr); // konstruktor domyslny z argumentem wskaünika do obiektu klasy Window
	AddStaffMemberPage(const AddStaffMemberPage& model); // konstruktor kopiujacy
	AddStaffMemberPage& operator = (const AddStaffMemberPage& model); // przeciazenie operatora przypisania
	~AddStaffMemberPage(); // destruktor

	void draw(); // metoda rysuje strone
	void service(); // metoda zarzadza operacjami na stronie
};

