#include "AddStaffMemberPage.h"

#include "CmdManager.h"

#include <iostream>

AddStaffMemberPage::AddStaffMemberPage(Window* window, StaffPage* staffPage) : Page(window)
{
	this->header = TextBox('#', "##   Dodawanie pracownika   ##");

	this->staffList = staffPage->getStaffList();

	this->resetValues();
}

AddStaffMemberPage::~AddStaffMemberPage()
{
	delete this->staffMember;
}

void AddStaffMemberPage::resetValues()
{
	this->currentStep = 1;

	this->firstName.clear();
	this->lastName.clear();
	this->age = 0;
	this->academic_degrees.clear();
}

void AddStaffMemberPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	std::cout << std::endl;
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	std::cout << "Imie:     | ";
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
	std::cout << this->firstName << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	std::cout << "Nazwisko: | ";
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
	std::cout << this->lastName << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	std::cout << "Wiek:     | ";
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
	if (this->age == 0)
		std::cout << ' ' << std::endl;
	else
		std::cout << this->age << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	std::cout << "Tytuly: | ";
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
	std::cout << this->academic_degrees << std::endl;

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
}

void AddStaffMemberPage::service()
{
	switch (this->currentStep)
	{
	case 1:
		std::cout << "Podaj imie: (min. 3 litery)" << std::endl;
		std::cin >> this->firstName;
		while (!std::cin.good() || this->firstName.length() < 3)
		{
			this->firstName.clear();
			this->getWindow()->refresh();
			std::cout << "Podaj imie: (min. 3 litery)" << std::endl;
			std::cin.clear();
			std::cin >> this->firstName;
		}
		break;
	case 2:
		std::cout << "Podaj nazwisko: (min. 3 litery)" << std::endl;
		std::cin >> this->lastName;
		while (!std::cin.good() || this->lastName.length() < 3)
		{
			this->lastName.clear();
			this->getWindow()->refresh();
			std::cout << "Podaj nazwisko: (min. 3 litery)" << std::endl;
			std::cin.clear();
			std::cin >> this->lastName;
		}
		break;
	case 3:
		std::cout << "Podaj wiek: (min. 30, max. 100)" << std::endl;
		std::cin >> this->age;
		while (!std::cin.good() || this->age < 20 || this->age > 100)
		{
			this->age = 0;
			this->getWindow()->refresh();
			std::cout << "Podaj wiek: (min. 30, max. 100)" << std::endl;
			std::cin.clear();
			std::cin >> this->age;
		}
		break;
	case 4:
		std::cout << "Podaj tytul(y): (min 3 litery)" << std::endl;
		std::cin >> this->academic_degrees;
		while (!std::cin.good() || this->academic_degrees.length() < 3)
		{
			this->academic_degrees.clear();
			this->getWindow()->refresh();
			std::cout << "Podaj tytul(y): (min 3 litery)" << std::endl;
			std::cin.clear();
			std::cin >> this->academic_degrees;
		}
		break;
	default:
		this->staffMember = new StaffMember(this->firstName, this->lastName, this->age, this->academic_degrees);

		int id = this->staffList->addMember(this->staffMember);

		this->getWindow()->refresh();
		std::cout << "Dodano nowego pracownika o id " << id << std::endl << std::endl;

		Sleep(2000);

		this->resetValues();
		this->getWindow()->setActivePage(2);
		break;
	}

	if (this->currentStep <= 4)
	{
		this->currentStep++;
		this->getWindow()->refresh();
		this->service();
	}
}
