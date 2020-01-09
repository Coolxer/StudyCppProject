#include "AddLessonPage.h"
#include <iostream>
#include "CmdManager.h"

#include "Lesson.h"

AddLessonPage::AddLessonPage(Window* window) : AddPage(window)
{
	this->header = TextBox('#', "##   Dodawanie zajecia   ##");
}

AddLessonPage::~AddLessonPage()
{
	
}

void AddLessonPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	this->drawParagraph("Typ:     | ");
	std::cout << this->strings[0] << std::endl;

	this->drawParagraph("Name: | ");
	std::cout << this->strings[1] << std::endl;

	this->drawParagraph("Godzina rozpoczecia:     | ");
	this->checkNumber(this->numbers[0]);

	this->drawParagraph("Czas trwania: | ");
	this->checkNumber(this->numbers[1]);

	this->drawParagraph("Max. ilosc miejsc | ");
	this->checkNumber(this->numbers[2]);
}

void AddLessonPage::service()
{
	switch (this->getCurrentStep())
	{
	case 1:
		std::cout << "Podaj typ: (wyklad / cwiczenia / laboratorium / projekt)" << std::endl;
		std::cin >> this->strings[0];
		while (!std::cin.good() || (this->strings[0] != "wyklad" && this->strings[0] != "cwiczenia" && this->strings[0] != "laboratorium" && this->strings[0] != "projekt"))
		{
			this->strings[0].clear();
			this->getWindow()->refresh();
			std::cout << "Podaj typ: (wyklad / cwiczenia / laboratiorum / projekt)" << std::endl;
			std::cin.clear();
			std::cin >> this->strings[0];
		}
		break;
	case 2:
		this->testString("Podaj nazwe: (min. 3 litery)", 1);
		break;
	case 3:
		this->testNumber("Podaj godzine rozpoczecia: (min 8 max 18, tylko pelne godziny)", 0, 8, 10);
		break;
	case 4:
		this->testNumber("Podaj czas trwania: (min 120, max 240 [w min.])", 1, 120, 240);
		break;
	case 5:
		this->testNumber("Podaj max. ilosc miejsc: (min 5, max 100)", 2, 5, 100);
		break;
	default:
		int id = this->objectList->addObject(new Lesson(this->strings[0], this->strings[1], this->numbers[0], this->numbers[1], this->numbers[2]));

		this->getWindow()->refresh();
		std::cout << "Dodano nowe zajecia o id " << id << std::endl << std::endl;

		Sleep(2000);

		this->resetValues();
		this->getWindow()->setActivePage(2);
		break;
	}

	this->increaseCurrentStep();
	this->getWindow()->refresh();
	this->service();
}
