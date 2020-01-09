#include "AddStudentPage.h"
#include <iostream>
#include "CmdManager.h"

#include "Student.h"

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
	std::cout << this->strings[0] << std::endl;

	this->drawParagraph("Nazwisko: | ");
	std::cout << this->strings[1] << std::endl;

	this->drawParagraph("Wiek:     | ");
	this->checkNumber(this->numbers[0]);

	this->drawParagraph("Kierunek: | ");
	std::cout << this->strings[2] << std::endl;

	this->drawParagraph("Stopien:  | ");
	this->checkNumber(this->numbers[1]);

	this->drawParagraph("Rok:      | ");
	this->checkNumber(this->numbers[2]);

	this->drawParagraph("Typ:      | ");
	std::cout << this->strings[3] << std::endl;

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
}

void AddStudentPage::service()
{
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
		std::cin >> this->strings[3];
		while (!std::cin.good() || (this->strings[3] != "stacjonarne" && this->strings[3] != "zaoczne"))
		{
			this->strings[3].clear();
			this->getWindow()->refresh();
			std::cout << "Podaj typ: (stacjonarne lub zaoczne)" << std::endl;
			std::cin.clear();
			std::cin >> this->strings[3];
		}
		break;
	default:
		int index = this->objectList->addObject(new Student(this->strings[0], this->strings[1], this->numbers[0], this->strings[2], this->numbers[1], this->numbers[2], this->strings[3]));

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
