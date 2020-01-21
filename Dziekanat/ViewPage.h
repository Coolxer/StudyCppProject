#pragma once
#include "Page.h"
#include "TextBox.h"
#include "ObjectList.h"

/* Klasa sluzaca do wyswietlania list */
/* Klasa dziedziczy po klasie Page */

class ViewPage: public Page
{
private:
	TextBox header; // naglowek strony
	TextBox info; // okienko informacyjne

	ObjectList* objectList; // wskaznik na liste obiektow

	int parentWindowIndex; // numer okna nadrzednego

public:
	ViewPage(Window* window = nullptr, std::string headerText = "", int parentWindowIndex = 0); // konstruktor domyslny
	ViewPage(const ViewPage& model); // konstruktor kopiujacy
	ViewPage& operator = (const ViewPage& model); // przeciazenie operatora przypisania
	~ViewPage(); // destruktor

	void init(ObjectList* objectList); // metoda ustawia wskaznik na liste obiektow

	void draw(); // metoda rysuje strone
	void service(); // metoda zarzadza operacjami na stronie
};

