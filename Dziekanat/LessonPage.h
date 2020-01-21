#pragma once
#include "MainPage.h"
#include "LessonList.h"

/* Klasa reprezentujaca strone nawigacyjna dotyczaca zajec */
/* Klasa dziedziczy klase MainPage */

class LessonPage : public MainPage
{
private:
	Menu menu; // menu nawigacyjne
	LessonList lessonList; // lista zajec
public:
	LessonPage(Window* window = nullptr); // konstruktor domyslny z argumentem wskaünika do obiektu klasy Window
	LessonPage(const LessonPage& model); // konstruktor kopiujacy
	LessonPage& operator = (const LessonPage& model); // przeciazenie operatora przypisania
	~LessonPage(); // destruktor

	LessonList* getLessonList(); // metoda zwraca wskaznik do listy zajec

	void service(); // metoda zarzadza operacjami na stronie
};

