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
		this->testString("Podaj imie: (min. 3 litery)", &this->firstName);
		break;
	case 2:
		this->testString("Podaj nazwisko: (min. 3 litery)", &this->lastName);
		break;
	case 3:
		this->testNumber("Podaj wiek: (min. 30, max. 100)", &this->age, 30, 100);
		break;
	case 4:
		this->testString("Podaj tytul(y): (min 3 litery)", &this->academic_degrees);
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

	this->currentStep++;
	this->getWindow()->refresh();
	this->service();
}

void AddStaffMemberPage::testString(std::string text, std::string* pointer)
{
	std::cout << text << std::endl;
	std::cin >> *pointer;
	while (!std::cin.good() || pointer->length() < 3)
	{
		pointer->clear();
		this->getWindow()->refresh();
		std::cout << text << std::endl;
		std::cin.clear();
		std::cin >> *pointer;
	}
}

void AddStaffMemberPage::testNumber(std::string text, int* pointer, int min, int max)
{
	std::cout << text << std::endl;
	std::cin >> *pointer;
	while (!std::cin.good() || *pointer < min || *pointer > max)
	{
		*pointer = 0;
		this->getWindow()->refresh();
		std::cout << text << std::endl;
		std::cin.clear();
		std::cin >> *pointer;
	}
}