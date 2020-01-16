#include "StaffList.h"

#include "StaffMember.h"

StaffList::StaffList()
{
	this->addObject(new StaffMember("Mariusz", "Nycz", 50, "inz")); // dodanie pracownika do listy pracownikow
	this->addObject(new StaffMember("Mariusz", "Maczka", 60, "prof")); // dodanie pracownika do listy pracownikow
}

bool StaffList::showProfessors()
{
	int count = 0; // ustawienie licznika pracownikow spelniajacych warunek na 0

	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		StaffMember* member = (StaffMember*)&this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu StaffMember
		if (member->isProfessor()) // sprawdzenie czy pracownik ma tytul profesora
		{
			member->show(); // wyswietlenie danych dot. pracownika
			count++; // zwiekszenie licznika pracownikow spelniajacych warunek
		}
	}

	if (count > 0)  // sprawdzenie czy istnieja pracownicy spelniajacy podany warunek
		return true;

	return false; // jesli nie ma wymaganych pracownikow, zwroc false
}