#include "StaffList.h"

#include "StaffMember.h"

StaffList::StaffList()
{
	this->addObject(new StaffMember("Mariusz", "Nycz", 50, "inz")); // dodanie pracownika do listy pracownikow
	this->addObject(new StaffMember("Mariusz", "Maczka", 60, "prof")); // dodanie pracownika do listy pracownikow
}

void StaffList::showProfessors()
{
	int count = 0; // ustawienie licznika pracownikow spelniajacych warunek na 0
	bool firstOccurrence = true; // ustawienie flagi sygnalizujacej, ze napotkano pierwszy pasujacy wynik

	for (int i = 0; i < this->size; i++)
	{
		StaffMember* member = (StaffMember*)this->objects[i]; // pobranie wskaznika na aktualny w iteracji obiekt typu StaffMember
		if (member->isProfessor()) // sprawdzenie czy pracownik ma tytul profesora
		{
			if (firstOccurrence)
			{
				StaffMember::showHeader();
				firstOccurrence = false;
			}

			member->show(); // wyswietlenie danych dot. pracownika
			count++; // zwiekszenie licznika pracownikow spelniajacych warunek
		}
	}

	if (count == 0)  // sprawdzenie czy istnieja pracownicy spelniajacy podany warunek
		std::cout << "Nie ma profesorow" << std::endl;
}