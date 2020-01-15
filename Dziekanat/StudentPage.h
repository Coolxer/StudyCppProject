#pragma once
#include "MainPage.h"

#include "StudentList.h"
#include "LessonList.h"

/* Klasa reprezentujaca strone nawigacyjna dotyczaca studentow */
/* Klasa dziedziczy klase MainPage */

class StudentPage : public MainPage
{
private:
	Menu menu; // menu nawigacyjne

	StudentList studentList; // lista studentow
	LessonList* lessonList; // wskaznik na liste zajec
public:
	StudentPage(Window* window); // konstruktor z argumentem wskaünika do obiektu klasy Window
	~StudentPage(); // destruktor

	StudentList* getStudentList(); // metoda zwraca wskaznik do listy studentow

	void init(LessonList* lessonList); // metoda ustawia wskaznik na liste zajec

	void service(); // metoda zarzadza operacjami na stronie
};

