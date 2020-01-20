#pragma once
#include "Person.h"
#include "Study.h"

/* Klasa reprezentujaca studenta */
/* Klasa dziedziczy klase Person */

class Student :public Person
{
private:
	int index; // nr indeksu
	Study study; // obiekt reprezentujacy dane dotyczace studiow

public:
	Student(std::string firstName = "", std::string lastName = "", int age = 0, std::string field = "", int level = 0, int year = 0, std::string type = ""); // konstruktor domyslny
	~Student(); // destruktor

	bool operator ==(const Student& s); // przeciazenie operatora porownania klasy Student

	Study* getStudy(); // metoda zwraca wskaznik na obiekt typu Study
	
	void changeStudyYear(int year); // metoda zmienia nr roku studiow
	void changeStudyType(std::string type); // metoda zmienia typ studiowania

	void showHeader(); // metoda wyswietla naglowek informacyjny
	void show(bool withHeader = false); // metoda wyswietla konkretne dane studenta
};

