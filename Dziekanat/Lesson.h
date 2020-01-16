#pragma once
#include <iostream>
#include <vector>

#include "Student.h"
#include "StaffMember.h"

#include "Object.h"

/* Klasa reprezentujaca zajecia */
/* Klasa dziedziczy klase Object */

class Lesson: public Object
{
private:
	std::string type; // typ zajec: wyklad / cwiczenia / laboratoria / projekt
	std::string name; // nazwa zajec
	int startTime; // godzina rozpoczecia zajec
	int duration; // czas trwania zajec

	int maxPlaces; // maksymalna liczba studentow
	int occupiedPlaces; // aktualna liczba studentow zapisana na zajecia

	StaffMember* staffMember; // prowadzacy zajecia
	std::vector <Student> students; // studenci zapisani na zajecia

public:
	Lesson() {} // konstruktor domyslny
	~Lesson(); // destruktor
	Lesson(std::string type, std::string name, int startTime, int duration, int maxPlaces); // konstruktor 

	std::string getType() const; // metoda zwraca typ zajec
	std::string getName() const; // metoda zwraca nazwe zajec
	int getStartTime() const; // metoda zwraca godzine rozpoczecia zajec
	int getDuration() const; // metoda zwraca czas trwania zajec
	int getMaxPlaces() const; // metoda zwraca maksymalna liczbe studentow
	int getOccupiedPlaces() const; // metoda zwraca aktualna liczbe studentow

	StaffMember* getStaffMember() const; // metoda zwraca prowadzacego zajecia

	int consistsStudent(Student* student); // metoda sprawdza czy student jest zapisany na zajecia
										   // jesli tak zwraca jego nr na liscie zajec
										   // jesli nie zwraca -1

	void removeStudent(Student* student, int id); // metoda skresla studenta z listy zajec
	void removeStaffMember(); // metoda zwalnia prowadzacego z zajec

	bool addStudent(Student* student); // metoda dopisuje studenta do listy zajec
	bool setStaffMember(StaffMember* staffMember); // metoda zatrudnia pracownika jako prowadzacego zajecia
	
	void showStudents(); // metoda wyswietla liste studentow zapisanych na zajecia

	void showHeader(); // metoda wyswietla naglowek informacyjny
	void show(bool withHeader = false); // metoda wyswietla konkretne dane zajec
};

