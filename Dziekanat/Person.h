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
	Person(std::string firstName = "", std::string lastName = "", int age = 0); // konstruktor domyslny z parametrami: imie, nazwisko i wiek
	Person(const Person& model); // konstruktor kopiujacy
	Person& operator = (const Person& model); // przeciazenie operatora przypisania
	bool operator ==(const Object& model); // przeciazenie operatora porownania
	~Person(); // destruktor

	std::string getFirstName() const; // metoda zwraca imie
	std::string getLastName() const; // metoda zwraca nazwisko
	int getAge() const; // metoda zwraca wiek
};

