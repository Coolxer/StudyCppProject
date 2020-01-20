#pragma once
#include "Person.h"

/* Klasa reprezentujaca pracownika */
/* Klasa dziedziczy klase Person */

class StaffMember :public Person
{
private:
	std::string academic_degrees; // stopnie naukowe
	int cash; // wynagrodzenie
	int numberOfLessonsProvided; // liczba prowadzonych zajec

	/* ROZPISKA WYNAGRODZEN ZA JEDNE ZAJECIA
		lic/inz = 200, 
		mgr = 400, 
		dr = 700, 
		prof = 1000
	*/

	void calcCash(); // metoda oblicza wynagrodzenie pracownika

public:
	StaffMember(std::string firstName = "", std::string lastName = "", int age = 0, std::string academic_degrees = ""); // konstruktor parametrowy
	~StaffMember(); // destruktor

	std::string getAcademicDegrees() const; // metoda zwraca stopnie naukowe
	int getCash() const; // metoda zwraca wynagrodzenie pracownika

	bool isProfessor() const; // metoda sprawdza czy pracownik ma tytul profesora

	void increaseLessons(); // metoda zwieksza liczbe prowadzonych lekcji przez pracownika

	void showHeader(); // metoda wyswietla naglowek informacyjny
	void show(bool withHeader = false); // metoda wyswietla konkretne dane pracownika
};

