#pragma once
#include <string>

/* Klasa reprezentujaca dane dotyczace studiow */

class Study
{
private:
	std::string field; // kierunek studiow
	int level; // stopien studiow
	int year; // rok studiow
	std::string type; // typ studiow
public:
	Study() {} // konstruktor domyslny
	//Study(std::string field = "inf", int level = 1, int year = 2, std::string type = "zaoczne");

	void init(std::string field, int level, int year, std::string type); // metoda ustawia dane dot. studiow

	std::string getField() const; // metoda zwraca kierunek studiow
	int getLevel() const; // metoda zwraca stopien studiow
	int getYear() const; // metoda zwraca rok studiow
	std::string getType() const; // metoda zwraca typ studiow

	void setField(std::string field); // metoda ustawia kierunek studiow
	void setLevel(int level); // metoda ustawia stopien studiow
	void setYear(int year); // metoda ustawia rok studiow
	void setType(std::string type); // metoda ustawia typ studiow
};

