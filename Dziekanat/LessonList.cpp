#include "LessonList.h"

LessonList::LessonList()
{
	this->addObject(new Lesson("projekt", "programowanie", 14, 120, 15)); // dodanie zajec do listy zajec
	this->addObject(new Lesson("wyklad", "systemy", 8, 240, 80)); // dodanie zajec do listy zajec
	this->addObject(new Lesson("laboratorium", "systemy_operacyjne", 10, 180, 15)); // dodanie zajec do listy zajec
	this->addObject(new Lesson("cwiczenia", "metody_numeryczne", 9, 120, 30)); // dodanie zajec do listy zajec
	this->addObject(new Lesson("laboratorium", "elektronika", 13, 120, 15)); // dodanie zajec do listy zajec
	this->addObject(new Lesson("cwiczenia", "algorytmy", 18, 120, 30)); // dodanie zajec do listy zajec
	this->addObject(new Lesson("projekt", "metody_numeryczne", 16, 120, 15)); // dodanie zajec do listy zajec
	this->addObject(new Lesson("laboratorium", "programowanie", 12, 120, 15)); // dodanie zajec do listy zajec
	this->addObject(new Lesson("wyklad", "algorytmy", 8, 180, 100)); // dodanie zajec do listy zajec
	this->addObject(new Lesson("projekt", "systemy", 14, 120, 15)); // dodanie zajec do listy zajec
}

LessonList::~LessonList()
{
	
}

Lesson* LessonList::getLessonByNameAndType(std::string name, std::string type)
{
	for (int i = 0; i < this->size; i++)
	{
		Lesson* lesson = (Lesson*)this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Lesson

		if (lesson->getName() == name && lesson->getType() == type) // sprawdzenie czy zajecia maja nazwe i typ taki jak podany w argumentach
			return lesson;                                            // jesli tak to zwraca true
	}

	return nullptr; // jesli zajecia o podanej nazwie i typie nie istnieja to zwraca false
}

void LessonList::removeStaffMemberFromLessons(StaffMember* staffMember)
{
	for (int i = 0; i < this->size; i++)
	{
		Lesson* lesson = (Lesson*)this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Lesson
		if (lesson->getStaffMember() == staffMember) // sprawdzenie czy prowadzacy zajecia jest taki sam jak podany w argumencie metody
			lesson->removeStaffMember();             // jesli tak to zwalnia prowadzacego te zajecia
	}
}

void LessonList::removeStudentFromLessons(Student* student)
{
	int x;

	for (int i = 0; i < this->size; i++)
	{
		Lesson* lesson = (Lesson*)this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Lesson
		x = lesson->consistsStudent(student); // sprawdzenie czy student jest zapisany na zajecia, jesli tak to x != -1

		if (x != -1) // jesli student jest zapisany na zajecia to usun go z listy tych zajec
			lesson->removeStudent(student, x);
	}
}

void LessonList::showSpecificType(std::string type)
{
	int count = 0; // ustawienie licznika zajec spelniajacych warunek na 0
	bool firstOccurrence = true; // ustawienie flagi sygnalizujacej, ze napotkano pierwszy pasujacy wynik

	for (int i = 0; i < this->size; i++)
	{
		Lesson* lesson = (Lesson*)this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Lesson
		if (lesson->getType() == type) // sprawdzenie czy zajecia maja wymagany typ
		{
			if (firstOccurrence)
			{
				lesson->showHeader();
				firstOccurrence = false; // zmiana stanu flagi sygnalizujacej pierwszy napotkany wynik
			}

			lesson->show(); // wyswietlenie danych dotyczacych konkretnych zajec
			count++; // zwiekszenie licznika zajec spelniajacych warunek
		}
	}

	if (count == 0) // sprawdzenie czy istnieja zajecia spelniajace podany warunek
		std::cout << "Nie ma zajec tego typu" << std::endl;
}
