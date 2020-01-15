#pragma once
#include <string>

#include "Object.h"

/* Klasa reprezentujaca osobe */
/* Klasa dziedziczy (rozszerza) klase Object */

class Person: public Object
{
private:
	std::string firstName; // imie
	std::string lastName; // nazwisko
	int age; // wiek
public:
	Person(){} // konstruktor domyslny
	Person(std::string firstName, std::string lastName, int age); // konstruktor z parametrami: imie, nazwisko i wiek

	std::string getFirstName() const; // metoda zwraca imie
	std::string getLastName() const; // metoda zwraca nazwisko
	int getAge() const; // metoda zwraca wiek
};

