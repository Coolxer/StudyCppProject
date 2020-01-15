#pragma once
#include <vector>
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
	std::vector <Object*> objects; // tablica obiektow
public:
	ObjectList(); // konstruktor domyslny
	~ObjectList(); // destruktor

	void setStartIndex(int startIndex); // metoda ustawia startowy numer identyfikacyjny

	int addObject(Object* o); // metoda dodaje obiekt do tablicy
	int removeObject(int index); // metoda usuwa obiekt z tablicy
	Object* getObjectByIndex(int index); // metoda zwraca obiekt na podstawie numeru identyfikacyjnego

	bool showAll(); // metoda wyswietla wszystkie obiekty z tablicy
	bool showByIndex(int index); // metoda wyswietla obiekt z tablicy na podstawie numeru identyfikacyjnego

	int getNumberOfObjects(); // metoda zwraca ilosc elementow tablicy
};

