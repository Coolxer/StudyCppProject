#pragma once
#include "ObjectList.h"

/* Klasa reprezentujaca liste pracownikow */
/* Klasa dziedziczy klase ObjectList */

class StaffList : public ObjectList
{
public:
	StaffList(); // konstruktor domyslny
	~StaffList(); // destruktor

	void showProfessors(); // metoda wyswietla wszystkich pracownikow z tytulem naukowym prof.
};

