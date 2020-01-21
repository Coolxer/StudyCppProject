#include "AddStaffMemberPage.h"
#include <iostream>
#include "CmdManager.h"

#include "StaffMember.h"

AddStaffMemberPage::AddStaffMemberPage(Window* window) : AddPage(window)
{
	this->header = TextBox('#', "##   Dodawanie pracownika   ##");
}

AddStaffMemberPage::AddStaffMemberPage(const AddStaffMemberPage& model)
{
	this->header = model.header;
}

AddStaffMemberPage& AddStaffMemberPage::operator = (const AddStaffMemberPage& model)
{
	this->header = model.header;

	return *this;
}

AddStaffMemberPage::~AddStaffMemberPage()
{

}

void AddStaffMemberPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	this->drawParagraph("Imie:     | "); // wyswietlenie paragrafu dot. imienia
	std::cout << this->strings[0] << std::endl; // wyswietlenie aktualnego imienia, jesli nie wpisane to ""

	this->drawParagraph("Nazwisko: | ");
	std::cout << this->strings[1] << std::endl;

	this->drawParagraph("Wiek:     | ");
	this->checkNumber(this->numbers[0]);

	this->drawParagraph("Tytul: | ");
	std::cout << this->strings[2] << std::endl;

	std::cout << std::endl;
}

void AddStaffMemberPage::service()
{
	switch (this->currentStep) // switch na podstawie aktualnego kroku dodawania nowego pracownika
	{
	case 1:
		this->testString("Podaj imie: (min. 3 litery)", 0); // pobranie odpowiedniego imienia pracownika (pobranie + walidacja)
		break;
	case 2:
		this->testString("Podaj nazwisko: (min. 3 litery)", 1); // pobranie odpowiedniego imienia pracownika (pobranie + walidacja)
		break;
	case 3:
		this->testNumber("Podaj wiek: (min. 30, max. 100)", 0, 30, 100); // pobranie odpowiedniego wieku pracownika (pobranie + walidacja)
		break;
	case 4:
		this->testString("Podaj tytul(y): (min 3 litery)", 2); // pobranie odpowiednich tytulow naukowych pracownika (pobranie + walidacja)
		break;
	default:
		// dodanie nowego pracownika do listy
		int id = this->objectList->addObject(new StaffMember(this->strings[0], this->strings[1], this->numbers[0], this->strings[2]));

		this->getWindow()->refresh();
		std::cout << "Dodano nowego pracownika o id " << id << std::endl << std::endl;

		Sleep(2000);

		this->resetValues(); // zresetowanie wszystkich wpisywanych wartosci
		this->getWindow()->setActivePage(2); // powrot do glownej strony studentow
		break;
	}

	this->currentStep++; // zwiekszenie postepu dodawania nowego studenta
	this->getWindow()->refresh();  // odswiezenie strony
	this->service(); // powrot na poczatek metody
}
