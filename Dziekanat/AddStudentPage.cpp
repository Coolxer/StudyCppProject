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
			std::cout << "Podaj wiek: (min. 20, max. 100)" << std::endl;
			std::cin >> this->age;
			while (!std::cin.good() || this->age < 20 || this->age > 100)
			{
				this->age = 0;
				this->getWindow()->refresh();
				std::cout << "Podaj wiek: (min. 20, max. 100)" << std::endl;
				std::cin.clear();
				std::cin >> this->age;
			}
			break;
		case 4:
			std::cout << "Podaj kierunek: (min 3 litery)" << std::endl;
			std::cin >> this->field;
			while (!std::cin.good() || this->field.length() < 3)
			{
				this->field.clear();
				this->getWindow()->refresh();
				std::cout << "Podaj kierunek: (min 3 litery)" << std::endl;
				std::cin.clear();
				std::cin >> this->field;
			}
			break;
		case 5:
			std::cout << "Podaj stopien: (1 lub 2)" << std::endl;
			std::cin >> this->level;
			while (!std::cin.good() || (this->level != 1 && this->level !=2))
			{
				this->level = 0;
				this->getWindow()->refresh();
				std::cout << "Podaj stopien: (1 lub 2)" << std::endl;
				std::cin.clear();
				std::cin >> this->level;
			}
			break;
		case 6:
			std::cout << "Podaj rok: (1-4)" << std::endl;
			std::cin >> this->year;
			while (!std::cin.good() || this->year < 1 || this->year > 4)
			{
				this->year = 0;
				this->getWindow()->refresh();
				std::cout << "Podaj rok: (1-4)" << std::endl;
				std::cin.clear();
				std::cin >> this->year;
			}
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

	if (this->currentStep <= 7)
	{
		this->currentStep++;
		this->getWindow()->refresh();
		this->service();
	}
}
