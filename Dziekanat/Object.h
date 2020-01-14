#pragma once
#include <string>

/* Klasa reprezentujaca obiekt */
/* Nie mozna utworzyc obiektow tej klasy, bo jest ona abstrakcyjna */
/* Klasa posiada 2 metody czysto wirtualne: showHeader() i show(bool withHeader = false) */
/* Metody te musza byc przesloniete w klasach potomnych, inaczej kompilator zwroci blad*/

class Object
{
private:
	int index; // numer identyfikacyjny

public:
	Object() {} // konstruktor domyslny

	int getIndex() const; // metoda zwraca numer identyfikacyjny
	void setIndex(int index); // metoda ustawia numer identyfikacyjny

	virtual void showHeader() = 0; // metoda czysto wirtualna (bez definicji) -> musi byc przeslonieta w klasie potomnej
	virtual void show(bool withHeader = false) = 0; // metoda czysto wirtualna (bez definicji) -> musi byc przeslonieta w klasie potomnej
};

