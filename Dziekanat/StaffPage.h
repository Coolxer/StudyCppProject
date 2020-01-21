#pragma once
#include "MainPage.h"

#include "StaffList.h"
#include "LessonList.h"

/* Klasa reprezentujaca strone nawigacyjna dotyczaca pracownikow */
/* Klasa dziedziczy klase MainPage */

class StaffPage : public MainPage
{
private:
	Menu menu; // menu nawigacyjne

	StaffList staffList; // lista pracownikow
	LessonList* lessonList; // wskaznik na liste zajec
public:
	StaffPage(Window* window = nullptr); // konstruktor z argumentem wskaünika do obiektu klasy Window
	StaffPage(const StaffPage& model); // konstruktor kopiujacy
	StaffPage& operator = (const StaffPage& model); // przeciazenie operatora przypisania
	~StaffPage(); // destruktor

	StaffList* getStaffList(); // metoda zwraca wskaznik na liste pracownikow

	void init(LessonList* lessonList); // metoda ustawia wskaznik na liste zajec

	void service(); // metoda zarzadza operacjami na stronie
};

