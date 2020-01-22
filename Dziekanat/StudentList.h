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

	void showByDepartment(std::string department); // metoda wyswietla studentow wedlug wydzialu studiow
	void showByField(std::string field); // metoda wyswietla studentow wedlug kierunku studiow
	void showByType(std::string type); // metoda wyswietla studentow wedlug typu studiowania
};

