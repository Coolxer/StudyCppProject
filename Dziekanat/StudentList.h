#pragma once
#include "ObjectList.h"
#include "Student.h"

/* Klasa reprezentujaca liste studentow */
/* Klasa dziedziczy klase ObjectList */

class StudentList: public ObjectList
{
public:
	StudentList(); // konstruktor domyslny
	~StudentList(); // destruktor

	void showByField(std::string field); // metoda wyswietla studentow wedlug kierunku studiow
	void showByType(std::string type); // metoda wyswietla studentow wedlug typu studiowania
};

