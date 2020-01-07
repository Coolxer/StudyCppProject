#include "AddStudentPage.h"

#include "CmdManager.h"

#include <iostream>

AddStudentPage::AddStudentPage(Window* window, StudentsPage* studentsPage) : Page(window)
{
	this->header = TextBox('#', "##   Dodawanie studenta   ##");

	this->studentsList = studentsPage->getStudentsList();
	
	this->resetValues();
}

AddStudentPage::~AddStudentPage()
{
	delete this->student;
}

void AddStudentPage::resetValues()
{
	this->currentStep = 1;

	this->firstName.clear();
	this->lastName.clear();
	this->age = 0;
	this->field.clear();
	this->level = 0;
	this->year = 0;
	this->type.clear();
}

void AddStudentPage::draw()
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
	if(this->age == 0)
		std::cout << ' ' << std::endl;
	else
		std::cout << this->age << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	std::cout << "Kierunek: | ";
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
	std::cout << this->field << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	std::cout << "Stopien:  | ";
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
	if (this->level == 0)
		std::cout << ' ' << std::endl;
	else
		std::cout << this->level << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	std::cout << "Rok:      | ";
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
	if (this->year == 0)
		std::cout << ' ' << std::endl;
	else
		std::cout << this->year << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	std::cout << "Typ:      | ";
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
	std::cout << this->type << std::endl;
	

	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->info.show();
}

void AddStudentPage::service()
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
			this->testNumber("Podaj wiek: (min. 20, max. 100)", &this->age, 20, 100);
			break;
		case 4:
			this->testString("Podaj kierunek: (min. 3 litery)", &this->field);
			break;
		case 5:
			this->testNumber("Podaj stopien: (1 lub 2)", &this->level, 1, 2);
			break;
		case 6:
			this->testNumber("Podaj rok: (1 - 4)", &this->year, 1, 4);
			break;
		case 7:
			std::cout << "Podaj typ: (stacjonarne lub zaoczne)" << std::endl;
			std::cin >> this->type;
			while (!std::cin.good() || (this->type != "stacjonarne" && this->type != "zaoczne"))
			{
				this->type.clear();
				this->getWindow()->refresh();
				std::cout << "Podaj typ: (stacjonarne lub zaoczne)" << std::endl;
				std::cin.clear();
				std::cin >> this->type;
			}
			break;
		default:
			this->student = new Student(this->firstName, this->lastName, this->age, this->field, this->level, this->year, this->type);

			int index = this->studentsList->addStudent(this->student);
			
			this->getWindow()->refresh();
			std::cout << "Dodano nowego studenta o indeksie " << index << std::endl << std::endl;

			Sleep(2000);

			this->resetValues();
			this->getWindow()->setActivePage(1);
			break;
	}

	this->currentStep++;
	this->getWindow()->refresh();
	this->service();
}

void AddStudentPage::testString(std::string text, std::string* pointer)
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

void AddStudentPage::testNumber(std::string text, int* pointer, int min, int max)
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
