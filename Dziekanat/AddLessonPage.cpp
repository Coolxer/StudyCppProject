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
		std::cout << "Podaj typ: (wyklad / cwiczenia / laboratiorum / projekt)" << std::endl;
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
		std::cout << "Podaj nazwe: (min. 3 litery)" << std::endl;
		std::cin >> this->name;
		while (!std::cin.good() || this->name.length() < 3)
		{
			this->name.clear();
			this->getWindow()->refresh();
			std::cout << "Podaj nazwe: (min. 3 litery)" << std::endl;
			std::cin.clear();
			std::cin >> this->name;
		}
		break;
	case 3:
		std::cout << "Podaj godzine rozpoczecia: (min 8 max 18, tylko pelne godziny)" << std::endl;
		std::cin >> this->startTime;
		while (!std::cin.good() || this->startTime < 8 || this->startTime > 18)
		{
			this->startTime = 0;
			this->getWindow()->refresh();
			std::cout << "Podaj godzine rozpoczecia: (min 8 max 18, tylko pelne godziny)" << std::endl;
			std::cin.clear();
			std::cin >> this->startTime;
		}
		break;
	case 4:
		std::cout << "Podaj czas trwania: (min 120, max 240 [w min.])" << std::endl;
		std::cin >> this->duration;
		while (!std::cin.good() || this->duration < 120 || this->duration > 240)
		{
			this->duration = 0;
			this->getWindow()->refresh();
			std::cout << "Podaj czas trwania: (min 120, max 240 [w min.])" << std::endl;
			std::cin.clear();
			std::cin >> this->duration;
		}
		break;
	case 5:
		std::cout << "Podaj max. ilosc miejsc: (min 5, max 100)" << std::endl;
		std::cin >> this->maxPlaces;
		while (!std::cin.good() || this->maxPlaces < 120 || this->maxPlaces > 240)
		{
			this->maxPlaces = 0;
			this->getWindow()->refresh();
			std::cout << "Podaj max. ilosc miejsc: (min 5, max 100)" << std::endl;
			std::cin.clear();
			std::cin >> this->maxPlaces;
		}
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

	if (this->currentStep <= 5)
	{
		this->currentStep++;
		this->getWindow()->refresh();
		this->service();
	}
}
