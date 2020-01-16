#include "Lesson.h"

#include <iostream>
#include "windows.h"

Lesson::Lesson(std::string type, std::string name, int startTime, int duration, int maxPlaces)
{
	this->type = type;
	this->name = name;
	this->startTime = startTime;
	this->duration = duration;

	this->maxPlaces = maxPlaces;
	this->occupiedPlaces = 0;

	this->staffMember = nullptr; // przypisanie wartosci nullptr do wskaznika, aby wskazywal na wartosc pusta
	this->students.clear(); // wyczyszczenie tablicy dynamicznej
}

Lesson::~Lesson()
{
	this->students.clear(); // wyczyszczenie tablicy dynamicznej
}

std::string Lesson::getType() const
{
	return this->type;
}

std::string Lesson::getName() const
{
	return this->name;
}

int Lesson::getStartTime() const
{
	return this->startTime;
}

int Lesson::getDuration() const
{
	return this->duration;
}

int Lesson::getMaxPlaces() const
{
	return this->maxPlaces;
}

int Lesson::getOccupiedPlaces() const
{
	return this->occupiedPlaces;
}

StaffMember* Lesson::getStaffMember() const
{
	return this->staffMember;
}

int Lesson::consistsStudent(Student* student)
{
	for (int i = 0; i < (int)this->students.size(); i++)
	{
		if (this->students[i] == *student) // sprawdzenie czy aktualny student w iteracji jest rowny podanemu poprzez wskaznik studentowi -> wykorzystanie przeciazenia operatora porownania
			return i;					   // jesli tak to zwraca numer tego studenta na liscie                     
	}

	return -1; // jesli studenta nie ma na liscie to zwraca -1
}

void Lesson::removeStudent(Student* student, int id)
{
	this->students.erase(this->students.begin() + id); // usuniecie studenta z listy zajec
	this->occupiedPlaces--; // zmiejszenie liczby studentow zapisanych na zajecia
}

void Lesson::removeStaffMember()
{
	//delete this->staffMember;
	this->staffMember = nullptr; // zwolnienie prowadzacego z zajec
}

bool Lesson::addStudent(Student* student)
{
	if (this->occupiedPlaces < this->maxPlaces) // sprawdzenie czy sa jeszcze wolne miejsce
	{
		for (int i = 0; i < (int)this->students.size(); i++)
		{
			if (this->students[i] == *student) // jesli student jest juz wpisany na liste to zwroc false
				return false;
		}

		this->students.push_back(*student); // dodanie studenta to listy
		this->occupiedPlaces++; // zwiekszenie liczby studentow zapisanych na zajecia
		return true;
	}

	return false; // jesli nie ma wolnych miejsc to zwraca false
}

bool Lesson::setStaffMember(StaffMember* staffMember)
{
	if (this->staffMember) // sprawdzenie czy zajecia nie maja juz przypisanego prowadzacego, jesli tak to zwraca false
		return false;

	this->staffMember = staffMember; // przypisanie pracownika do zajec

	return true;
}

bool Lesson::showStudents()
{
	if (this->students.size() == 0) // sprawdzenie czy do zajec sa przypisani jacys studenci, jesli nie to zwroc false
		return false;

	//Student::showHeader();

	for (int i = 0; i < (int)this->students.size(); i++)
		this->students[i].show(); // wyswietlenie danych wszystkich studentow zapisanych na zajecia

	return true;
}

void Lesson::showHeader()
{
	std::cout << " ID " << " Typ " << " Nazwa " << " Godzina rozpoczecia " << " Czas trwania " << " zajete / max "<< std::endl;
}

void Lesson::show(bool withHeader)
{
	if (withHeader) // parametr withHeader jest opcjonalny
		this->showHeader();

	std::cout << "-----------------" << std::endl;
	std::cout << this->getIndex() << " | " << this->type << " | " << this->name << " | " << this->startTime << " | " << this->duration << " | " << this->occupiedPlaces << "/" << this->maxPlaces << std::endl;
}
