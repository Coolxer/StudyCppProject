#include "AddStaffMemberPage.h"
#include <iostream>
#include "CmdManager.h"

AddStaffMemberPage::AddStaffMemberPage(Window* window, ObjectList* objectList) : AddPage(window, objectList)
{
	this->header = TextBox('#', "##   Dodawanie pracownika   ##");
}

AddStaffMemberPage::~AddStaffMemberPage()
{

}

void AddStaffMemberPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	this->drawParagraph("Imie:     | ");
	std::cout << this->getInputString(0) << std::endl;

	this->drawParagraph("Nazwisko: | ");
	std::cout << this->getInputString(1) << std::endl;

	this->drawParagraph("Wiek:     | ");
	this->checkNumber(this->getInputNumber(0));

	this->drawParagraph("Tytul: | ");
	std::cout << this->getInputString(2) << std::endl;

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
}

void AddStaffMemberPage::service()
{
	std::string inputString = "";

	switch (this->getCurrentStep())
	{
	case 1:
		this->testString("Podaj imie: (min. 3 litery)", 0);
		break;
	case 2:
		this->testString("Podaj nazwisko: (min. 3 litery)", 1);
		break;
	case 3:
		this->testNumber("Podaj wiek: (min. 30, max. 100)", 0, 30, 100);
		break;
	case 4:
		this->testString("Podaj tytul(y): (min 3 litery)", 2);
		break;
	default:
		//this->staffMember = new StaffMember(this->firstName, this->lastName, this->age, this->academic_degrees);

		//int id = this->staffList->addMember(this->staffMember);

		this->getWindow()->refresh();
		std::cout << "Dodano nowego pracownika o id " << id << std::endl << std::endl;

		Sleep(2000);

		this->resetValues();
		this->getWindow()->setActivePage(2);
		break;
	}

	this->increaseCurrentStep();
	this->getWindow()->refresh();
	this->service();
}
