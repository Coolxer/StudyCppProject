#include "StudentList.h"

#include "Student.h"
#include "windows.h"

StudentList::StudentList()
{
	this->setStartIndex(16000); // ustawienie startowego indeksu na 16000

	this->addObject(new Student("Lukasz", "Milos", 22, "informatyki", "informatyka", 1, 2, "zaoczne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Jakub", "Basztura", 24, "budownictwa", "biogospodarka", 1, 3, "stacjonarne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Grzegorz", "Szyfner", 27, "informatyki", "elektrotechnika", 2, 1, "zaoczne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Sebastian", "Stoch", 23, "informatyki", "elektrotechnika", 1, 3, "stacjonarne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Agnieszka", "Cichonska", 23, "zarzadzania", "logistyka", 1, 3, "zaoczne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Adrian", "Nowicki", 23, "informatyki", "informatyka", 1, 3, "stacjonarne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Adam", "Konieczny", 23, "zarzadzania", "zarzadzanie", 1, 3, "zaoczne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Natalia", "Krawczyk", 23, "chemiczny", "biotechnologia", 1, 3, "stacjonarne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Kamil", "Mazur", 23, "matematyki", "fizyka", 1, 3, "stacjonarne")); // dodanie studenta do listy studentow
	this->addObject(new Student("Weronika", "Skawinska", 23, "budownictwa", "architektura", 1, 3, "zaoczne")); // dodanie studenta do listy studentow
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