#include "StudentList.h"

#include "Student.h"
#include "windows.h"

StudentList::StudentList()
{
	this->setStartIndex(16000); // ustawienie startowego indeksu na 16000

	this->addObject(new Student("Lukasz", "Milos", 21, "inf", 1, 2, "zaoczne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Rafal", "Magrys", 22, "inf", 1, 2, "stacjonarne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Kuba", "Stanislawczyk", 21, "bud", 1, 2, "zaoczne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Damian", "Pietraszek", 27, "inf", 1, 2, "zaoczne")); // dodanie studenta do listy studentow
}

bool StudentList::showByField(std::string field)
{
	int count = 0; // ustawienie licznika studentow spelniajacych warunek na 0

	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Student* student = (Student*)&this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Student
		std::cout << student->getAge() << std::endl;
		Sleep(1500);
		/*
		if (student->getStudy()->getField() == field)
		{
			student->show();
			count++;
		}*/
	}

	if (count > 0) // sprawdzenie czy istnieja studenci spelniajacy podany warunek
		return true;

	return false; // jesli nie ma wymaganych studentow, zwroc false
}

bool StudentList::showByType(std::string type)
{
	int count = 0; // ustawienie licznika studentow spelniajacych warunek na 0

	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		Student* student = (Student*)&this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Student
		if (student->getStudy()->getType() == type) // sprawdzenie czy tryb studiow studenta jest zgodny z tym podanym jako argument metody
		{
			student->show(); // wyswietlenie danych dot. studenta
			count++; // zwiekszenie licznika studentow spelniajacych warunek
		}
	}

	if (count > 0) // sprawdzenie czy istnieja studenci spelniajacy podany warunek
		return true;

	return false; // jesli nie ma wymaganych studentow, zwroc false
}