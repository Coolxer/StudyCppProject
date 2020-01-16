#include "LessonList.h"

LessonList::LessonList()
{
	this->addObject(new Lesson("projekt", "programowanie", 5, 90, 30)); // dodanie zajec do listy zajec
	this->addObject(new Lesson("laboratorium", "systemy", 10, 120, 15)); // dodanie zajec do listy zajec
} 

Lesson* LessonList::getByName(std::string name)
{
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Lesson* lesson = (Lesson*)&this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Lesson
		if (lesson->getName() == name) // sprawadzenie czy zajecia maja nazwe taka jak podana jako argument
			return lesson;             // jesli tak to zwraca wskaznik na ta zajecie
	}

	return nullptr; // jesli zadane zajecia nie istnieja to zwraca pusty wskaznik
}

bool LessonList::lessonExist(std::string name, std::string type)
{
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Lesson* lesson = (Lesson*)&this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Lesson

		if (lesson->getName() == name && lesson->getType() == type) // sprawdzenie czy zajecia maja nazwe i typ taki jak podany w argumentach
			return true;                                            // jesli tak to zwraca true
	}

	return false; // jesli zajecia o podanej nazwie i typie nie istnieje to zwraca false
}

void LessonList::removeStaffMemberFromLessons(StaffMember* staffMember)
{
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Lesson* lesson = (Lesson*)&this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Lesson
		if (lesson->getStaffMember() == staffMember) // sprawdzenie czy prowadzacy zajecia jest taki sam jak podany w argumencie metody
			lesson->removeStaffMember();             // jesli tak to zwalnia prowadzacego te zajecia
	}
}

void LessonList::removeStudentFromLessons(Student* student)
{
	int x;

	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Lesson* lesson = (Lesson*)&this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Lesson
		x = lesson->consistsStudent(student); // sprawdzenie czy student jest zapisany na zajecia, jesli tak to x != -1

		if (x != -1) // jesli student jest zapisany na zajecia to usun go z listy tych zajec
			lesson->removeStudent(student, x);
	}
}

void LessonList::showByName(std::string name)
{
	bool exists = false;

	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Lesson* lesson = (Lesson*)&this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Lesson
		if (lesson->getName() == name) // sprawdzenie czy zajecia maja nazwe taka jaka zostala podana jako argument
		{
			lesson->show(true); // wyswietlenie danych dotyczacych konkretnych zajec
			exists = true;
		}
	}

	if(!exists) // jesli zajecia o podanej nazwie nie istnieja, wyswietl komunikat
		std::cout << "Nie ma zajec o podanej nazwie" << std::endl;
}

void LessonList::showSpecificType(std::string type)
{
	int count = 0; // ustawienie licznika zajec spelniajacych warunek na 0

	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Lesson* lesson = (Lesson*)&this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Lesson
		if (lesson->getType() == type) // sprawdzenie czy zajecia maja wymagany typ
		{
			lesson->show(); // wyswietlenie danych dotyczacych konkretnych zajec
			count++; // zwiekszenie licznika zajec spelniajacych warunek
		}
	}

	if (count == 0) // sprawdzenie czy istnieja zajecia spelniajace podany warunek
		std::cout << "Nie ma zajec tego typu" << std::endl;
}
