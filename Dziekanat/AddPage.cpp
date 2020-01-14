#include "AddPage.h"
#include <iostream>

#include "CmdManager.h"

AddPage::AddPage(Window* window) : Page(window)
{
	this->objectList = objectList;

	this->resetValues();
}

AddPage::~AddPage()
{
	delete this->objectList;
}

void AddPage::init(ObjectList* objectList)
{
	this->objectList = objectList;
}

int AddPage::getCurrentStep()
{
	return this->currentStep;
}

void AddPage::resetValues()
{
	this->currentStep = 1;

	for (int i = 0; i < 10; i++)
	{
		this->strings[i].clear();
		this->numbers[i] = 0;
	}
}

int AddPage::increaseCurrentStep()
{
	return ++this->currentStep;
}

void AddPage::checkNumber(int number)
{
	if (number == 0)
		std::cout << ' ' << std::endl;
	else
		std::cout << number << std::endl;
}

void AddPage::testString(std::string text, int id)
{
	std::cout << text << std::endl;
	std::cin >> this->strings[id];
	while (!std::cin.good() || this->strings[id].length() < 3)
	{
		this->strings[id].clear();
		this->getWindow()->refresh();
		std::cout << text << std::endl;
		std::cin.clear();
		std::cin >> this->strings[id];
	}
}

void AddPage::testNumber(std::string text, int id, int min, int max)
{
	std::cout << text << std::endl;
	std::cin >> this->numbers[id];
	while (!std::cin.good() || this->numbers[id] < min || this->numbers[id] > max)
	{
		this->numbers[id] = 0;
		this->getWindow()->refresh();
		std::cout << text << std::endl;
		std::cin.clear();
		std::cin >> this->numbers[id];
	}
}

void AddPage::drawParagraph(std::string text)
{
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_GREEN);
	std::cout << "-------------------------" << std::endl;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), FOREGROUND_RED);
	std::cout << text;
	SetConsoleTextAttribute(this->getWindow()->getConsole(), 15);
}

