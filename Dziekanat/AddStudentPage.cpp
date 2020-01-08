#include "AddStudentPage.h"
#include <iostream>
#include "CmdManager.h"

AddStudentPage::AddStudentPage(Window* window, ObjectList* objectList) : AddPage(window, objectList)
{
	this->header = TextBox('#', "##   Dodawanie studenta   ##");
}

AddStudentPage::~AddStudentPage()
{

}

void AddStudentPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	this->drawParagraph("Imie:     | ");
	std::cout << this->getInputString(0) << std::endl;

	this->drawParagraph("Nazwisko: | ");
	std::cout << this->getInputString(1) << std::endl;

	this->drawParagraph("Wiek:     | ");
	this->checkNumber(this->getInputNumber(0));

	this->drawParagraph("Kierunek: | ");
	std::cout << this->getInputString(2) << std::endl;

	this->drawParagraph("Stopien:  | ");
	this->checkNumber(this->getInputNumber(1));

	this->drawParagraph("Rok:      | ");
	this->checkNumber(this->getInputNumber(2));

	this->drawParagraph("Typ:      | ");
	std::cout << this->getInputString(3) << std::endl;

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
}

void AddStudentPage::service()
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
		this->testNumber("Podaj wiek: (min. 20, max. 100)", 0, 20, 100);
		break;
	case 4:
		this->testString("Podaj kierunek: (min. 3 litery)", 2);
		break;
	case 5:
		this->testNumber("Podaj stopien: (1 lub 2)", 1, 1, 2);
		break;
	case 6:
		this->testNumber("Podaj rok: (1 - 4)", 2, 1, 4);
		break;
	case 7:
		std::cout << "Podaj typ: (stacjonarne lub zaoczne)" << std::endl;
		std::cin >> inputString;
		while (!std::cin.good() || (inputString != "stacjonarne" && inputString != "zaoczne"))
		{
			inputString.clear();
			this->getWindow()->refresh();
			std::cout << "Podaj typ: (stacjonarne lub zaoczne)" << std::endl;
			std::cin.clear();
			std::cin >> inputString;
		}
		this->setString(3, inputString);
		break;
	default:
		//this->student = new Student(this->firstName, this->lastName, this->age, this->field, this->level, this->year, this->type);

		//int index = this->studentsList->addStudent(this->student);

		this->getWindow()->refresh();
		std::cout << "Dodano nowego studenta o indeksie " << index << std::endl << std::endl;

		Sleep(2000);

		this->resetValues();
		this->getWindow()->setActivePage(1);
		break;
	}

	this->increaseCurrentStep();
	this->getWindow()->refresh();
	this->service();
}
