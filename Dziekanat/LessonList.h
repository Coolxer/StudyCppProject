#pragma once
#include "ObjectList.h"
#include "Lesson.h"

#include "Student.h"

/* Klasa reprezentujaca liste zajec */
/* Klasa dziedziczy klase ObjectList */

class LessonList : public ObjectList
{
public:
	LessonList(); // konstruktor
	~LessonList(); // destruktor

	Lesson* getByName(std::string name); // metoda zwraca zajecie na podstawie nazwy
									     // jesli zajecie nie istnieje zwraca pusty wskaznik

	bool lessonExist(std::string name, std::string type); // metoda sprawdza czy zajecie o podanym typie i nazwie istnieje
														  // jesli tak zwraca prawde, inaczej falsz

	void removeStaffMemberFromLessons(StaffMember* staffMember); // metoda zwalnia pracownika ze wszystkich zajec, ktore prowadzil
	void removeStudentFromLessons(Student* student); // metoda skresla studenta z list wszystkich zajec, na ktore byl zapisany

	void showByName(std::string name); // metoda wyswietla dane zajec na podstawie nazwy

	void showSpecificType(std::string type); // metoda wyswietla dane wszystkich zajec danego typu
};

