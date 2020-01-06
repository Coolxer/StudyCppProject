#include "Window.h"

#include <iostream>
#include "MenuPage.h"
#include "StudentsPage.h"
#include "LessonsPage.h"

using namespace std;

Window::Window()
{
	this->console = GetStdHandle(STD_OUTPUT_HANDLE);

	this->pages[0] = new MenuPage(this);
	this->pages[1] = new StudentsPage(this);

	this->activePageIndex = 0;
}

Window::~Window()
{
	for (int i = 0; i < 2; i++)
		delete this->pages[i];
}

void Window::clear()
{
	system("cls");
}

void Window::drawActivePage()
{
	this->clear();
	this->pages[this->activePageIndex]->draw();
}

void Window::setActivePage(int pageIndex)
{
	this->activePageIndex = pageIndex;

	this->drawActivePage();
	this->pages[pageIndex]->service();
}

HANDLE Window::getConsole()
{
	return this->console;
}

