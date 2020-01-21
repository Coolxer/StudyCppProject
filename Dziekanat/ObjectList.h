#pragma once
#include <string>

#include "Student.h"
#include "StaffMember.h"
#include "Lesson.h"

/* Klasa umozliwiajaca dokonywanie operacji na obiektach */
/* Nie ma instancji tej klasy w programie (sluzy ona jako klasa bazowa)*/

class ObjectList
{
private:
	int index; // startowy numer identyfikacyjny
protected:
	Object** objects; // dynamiczna tablica wskaznikow na obiekty
	int size;
public:
	ObjectList(); // konstruktor domyslny
	ObjectList(const ObjectList& model); // konstruktor kopiujacy
	ObjectList& operator = (const ObjectList& model); // przeciazenie operatora przypisania
	~ObjectList(); // destruktor

	void setStartIndex(int startIndex); // metoda ustawia startowy numer identyfikacyjny

	int addObject(Object* o); // metoda dodaje obiekt do tablicy
	int removeObject(int index); // metoda usuwa obiekt z tablicy
	int objectExists(Object* object); // metoda sprawdza czy obiekt istnieje na liscie
	Object* getObjectByIndex(int index); // metoda zwraca obiekt na podstawie numeru identyfikacyjnego
	Object* getObjectByRealIndex(int index); // metoda zwraca obiekt na podstawie indeksu w tablicy dynamicznej

	void showAll(); // metoda wyswietla wszystkie obiekty z tablicy
	void showByIndex(int index); // metoda wyswietla obiekt z tablicy na podstawie numeru identyfikacyjnego

	int getNumberOfObjects(); // metoda zwraca ilosc elementow tablicy
};

