#include "Window.h"

#include <iostream>

#include "MenuPage.h"

#include "StudentPage.h"
#include "AddStudentPage.h"

#include "StaffPage.h"
#include "AddStaffMemberPage.h"

#include "LessonPage.h"
#include "AddLessonPage.h"

#include "ViewPage.h"

using namespace std;

Window::Window()
{
	this->console = GetStdHandle(STD_OUTPUT_HANDLE);

	this->pages[0] = new MenuPage(this, " DZIEKANAT ");
	this->pages[1] = new StudentPage(this, " STUDENT SERWIS ");
	this->pages[2] = new StaffPage(this, " GRONO PEDAGOGICZNE SERWIS ");
	this->pages[3] = new LessonPage(this, " ZAJECIA SERWIS ");

	this->pages[4] = new AddStudentPage(this);
	this->pages[6] = new AddStaffMemberPage(this);
	this->pages[8] = new AddLessonPage(this);

	this->pages[5] = new ViewPage(this, " LISTA STUDENTOW ", 1);
	this->pages[7] = new ViewPage(this, " LISTA PRACOWNIKOW ", 2);
	this->pages[9] = new ViewPage(this, " LISTA ZAJEC ", 3);

	MainPage* mainPage;
	AddPage* addPage;
	ViewPage* viewPage;

	mainPage = (MainPage*)this->pages[1];
	addPage = (AddPage*)this->pages[4];
	addPage->init(mainPage->getObjectList());
	viewPage = (ViewPage*)this->pages[5];
	viewPage->init(mainPage->getObjectList());

	mainPage = (MainPage*)this->pages[2];
	addPage = (AddPage*)this->pages[6];
	addPage->init(mainPage->getObjectList());
	viewPage = (ViewPage*)this->pages[7];
	viewPage->init(mainPage->getObjectList());

	mainPage = (MainPage*)this->pages[3];
	addPage = (AddPage*)this->pages[8];
	addPage->init(mainPage->getObjectList());
	viewPage = (ViewPage*)this->pages[9];
	viewPage->init(mainPage->getObjectList());

	this->activePageIndex = 0;
}

Window::~Window()
{
	for (int i = 0; i < 7; i++)
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

void Window::refresh()
{
	this->drawActivePage();
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

