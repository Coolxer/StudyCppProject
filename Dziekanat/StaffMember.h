#pragma once
#include "Person.h"

/* Klasa reprezentujaca pracownika */
/* Klasa dziedziczy klase Person */

class StaffMember :public Person
{
private:
	std::string academic_degree; // stopien naukowy
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
	StaffMember(std::string firstName = "", std::string lastName = "", int age = 0, std::string academic_degree = ""); // konstruktor parametrowy
	StaffMember(const StaffMember& model); // konstruktor kopiujacy
	StaffMember& operator = (const StaffMember& model); // przeciazenie operatora przypisania
	bool isEqual(Object* model); // metoda sprawdzajaca przy obiekt (wskazywany poprzez wskaznik) jest taki sam
	~StaffMember(); // destruktor

	std::string getAcademicDegree() const; // metoda zwraca stopien naukowy
	int getCash() const; // metoda zwraca wynagrodzenie pracownika

	bool isProfessor() const; // metoda sprawdza czy pracownik ma tytul profesora

	void increaseLessons(); // metoda zwieksza liczbe prowadzonych lekcji przez pracownika
	void decreaseLessons(); // metoda zwieksza liczbe prowadzonych lekcji przez pracownika

	void showHeader(); // metoda wyswietla naglowek informacyjny
	void show(bool withHeader = false); // metoda wyswietla konkretne dane pracownika
};

