#include "StudentList.h"

#include "Student.h"
#include "windows.h"

StudentList::StudentList()
{
	this->setStartIndex(16000); // ustawienie startowego indeksu na 16000

	this->addObject(new Student("Lukasz", "Milos", 21, "informatyki", "informatyka", 1, 2, "zaoczne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Rafal", "Magrys", 22, "informatyki", "infortmatyka", 1, 2, "stacjonarne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Kuba", "Stanislawczyk", 21, "informatyki", "informatyka", 1, 2, "zaoczne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Damian", "Pietraszek", 27, "informatyki", "informatyka", 1, 2, "zaoczne")); // dodanie studenta do listy studentow
}

StudentList::~StudentList()
{

}

void StudentList::showByDepartment(std::string department)
{
	int count = 0; // ustawienie licznika studentow spelniajacych warunek na 0
	bool firstOccurrence = true; // ustawienie flagi sygnalizujacej, ze napotkano pierwszy pasujacy wynik

	for (int i = 0; i < this->size; i++)
	{
		Student* student = (Student*)this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Student

		if (student->getStudy()->getDepartment() == department) // sprawdzenie czy student studiuje na podanym wydziale
		{
			if (firstOccurrence)
			{
				student->showHeader();
				firstOccurrence = false;
			}

			student->show();
			count++;
		}
	}

	if (count == 0) // sprawdzenie czy istnieja studenci spelniajacy podany warunek
		std::cout << "Nie ma studentow na tym wydziale" << std::endl;
}

void StudentList::showByField(std::string field)
{
	int count = 0; // ustawienie licznika studentow spelniajacych warunek na 0
	bool firstOccurrence = true; // ustawienie flagi sygnalizujacej, ze napotkano pierwszy pasujacy wynik

	for (int i = 0; i < this->size; i++)
	{
		Student* student = (Student*)this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Student

		if (student->getStudy()->getField() == field) // sprawdzenie czy student studiuje na podanym kierunku
		{
			if (firstOccurrence)
			{
				student->showHeader();
				firstOccurrence = false;
			}

			student->show();
			count++;
		}
	}

	if (count == 0) // sprawdzenie czy istnieja studenci spelniajacy podany warunek
		std::cout << "Nie ma studentow na tym kierunku" << std::endl;
}

void StudentList::showByType(std::string type)
{
	int count = 0; // ustawienie licznika studentow spelniajacych warunek na 0
	bool firstOccurrence = true; // ustawienie flagi sygnalizujacej, ze napotkano pierwszy pasujacy wynik

	for (int i = 0; i < this->size; i++)
	{
		Student* student = (Student*)this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu Student

		if (student->getStudy()->getType() == type) // sprawdzenie czy tryb studiow studenta jest zgodny z tym podanym jako argument metody
		{
			if (firstOccurrence)
			{
				student->showHeader();
				firstOccurrence = false;
			}

			student->show(); // wyswietlenie danych dot. studenta
			count++; // zwiekszenie licznika studentow spelniajacych warunek
		}
	}

	if (count == 0) // sprawdzenie czy istnieja studenci spelniajacy podany warunek
		std::cout << "Nie ma studentow " << type << "(ych)" << std::endl;
}