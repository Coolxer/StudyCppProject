#include "AddLessonPage.h"

#include "CmdManager.h"

#include <iostream>

AddLessonPage::AddLessonPage(Window* window, LessonsPage* lessonsPage) : Page(window)
{
	this->header = TextBox('#', "##   Dodawanie zajecia   ##");

	this->lessonsList = lessonsPage->getStaffList();

	this->resetValues();
}

AddLessonPage::~AddLessonPage()
{
	delete this->lesson;
}

void AddLessonPage::resetValues()
{
	this->currentStep = 1;

	this->type.clear();
	this->name.clear();
	this->startTime = 0;
	this->duration = 0;
}

void AddLessonPage::draw()
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	this->header.show();

	std::cout << std::endl;
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	std::cout << "Typ:     | ";
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
	std::cout << this->type << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	std::cout << "Name: | ";
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
	std::cout << this->name << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	std::cout << "Godzina rozpoczecia:     | ";
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
	if (this->startTime == 0)
		std::cout << ' ' << std::endl;
	else
		std::cout << this->startTime << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	std::cout << "Czas trwania: | ";
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
	if(this->duration == 0)
		std::cout << ' ' << std::endl;
	else
	std::cout << this->duration << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	std::cout << "Max. ilosc miejsc | ";
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
	if (this->maxPlaces == 0)
		std::cout << ' ' << std::endl;
	else
		std::cout << this->maxPlaces << std::endl;

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
}

void AddLessonPage::service()
{
	switch (this->currentStep)
	{
	case 1:
		std::cout << "Podaj typ: (wyklad / cwiczenia / laboratorium / projekt)" << std::endl;
		std::cin >> this->type;
		while (!std::cin.good() || (this->type != "wyklad" && this->type != "cwiczenia" && this->type != "laboratorium" && this->type != "projekt"))
		{
			this->type.clear();
			this->getWindow()->refresh();
			std::cout << "Podaj typ: (wyklad / cwiczenia / laboratiorum / projekt)" << std::endl;
			std::cin.clear();
			std::cin >> this->type;
		}
		break;
	case 2:
		this->testString("Podaj nazwe: (min. 3 litery)", &this->name);
		break;
	case 3:
		this->testNumber("Podaj godzine rozpoczecia: (min 8 max 18, tylko pelne godziny)", &this->startTime, 8, 10);
		break;
	case 4:
		this->testNumber("Podaj czas trwania: (min 120, max 240 [w min.])", &this->duration, 120, 240);
		break;
	case 5:
		this->testNumber("Podaj max. ilosc miejsc: (min 5, max 100)", &this->maxPlaces, 5, 100);
		break;
	default:
		this->lesson = new Lesson(this->type, this->name, this->startTime, this->duration, this->maxPlaces);

		int id = this->lessonsList->addLesson(this->lesson);

		this->getWindow()->refresh();
		std::cout << "Dodano nowe zajecie o id " << id << std::endl << std::endl;

		Sleep(2000);

		this->resetValues();
		this->getWindow()->setActivePage(2);
		break;
	}

	this->currentStep++;
	this->getWindow()->refresh();
	this->service();
}

void AddLessonPage::testString(std::string text, std::string* pointer)
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

void AddLessonPage::testNumber(std::string text, int* pointer, int min, int max)
{
	std::cout << text << std::endl;
	std::cin >> *pointer;
	while (!std::cin.good() || *pointer < 20 || *pointer > 100)
	{
		*pointer = 0;
		this->getWindow()->refresh();
		std::cout << text << std::endl;
		std::cin.clear();
		std::cin >> *pointer;
	}
}
