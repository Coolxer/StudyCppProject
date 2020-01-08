#include "AddLessonPage.h"
#include <iostream>
#include "CmdManager.h"

AddLessonPage::AddLessonPage(Window* window, ObjectList* objectList) : AddPage(window, objectList)
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
	std::cout << this->getInputString(0) << std::endl;

	this->drawParagraph("Name: | ");
	std::cout << this->getInputString(1) << std::endl;

	this->drawParagraph("Godzina rozpoczecia:     | ");
	this->checkNumber(this->getInputNumber(0));

	this->drawParagraph("Czas trwania: | ");
	this->checkNumber(this->getInputNumber(1));

	this->drawParagraph("Max. ilosc miejsc | ");
	this->checkNumber(this->getInputNumber(2));

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
}

void AddLessonPage::service()
{
	std::string inputString = "";

	switch (this->getCurrentStep())
	{
	case 1:
		std::cout << "Podaj typ: (wyklad / cwiczenia / laboratorium / projekt)" << std::endl;
		std::cin >> inputString;
		while (!std::cin.good() || (inputString != "wyklad" && inputString != "cwiczenia" && inputString != "laboratorium" && inputString != "projekt"))
		{
			inputString.clear();
			this->getWindow()->refresh();
			std::cout << "Podaj typ: (wyklad / cwiczenia / laboratiorum / projekt)" << std::endl;
			std::cin.clear();
			std::cin >> inputString;
		}
		this->setString(0, inputString);
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
		//Lesson* lesson = new Lesson(, this->name, this->startTime, this->duration, this->maxPlaces);

		//int id = this->lessonsList->addLesson(this->lesson);

		this->getWindow()->refresh();
		std::cout << "Dodano nowe zajecie o id " << id << std::endl << std::endl;

		Sleep(2000);

		this->resetValues();
		this->getWindow()->setActivePage(2);
		break;
	}

	this->increaseCurrentStep();
	this->getWindow()->refresh();
	this->service();
}
