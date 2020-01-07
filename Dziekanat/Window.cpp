#include "Window.h"

#include <iostream>

#include "MenuPage.h"

#include "StudentsPage.h"
#include "AddStudentPage.h"
#include "StudentsViewPage.h"

#include "StaffPage.h"
#include "AddStaffMemberPage.h"
#include "StaffViewPage.h"

#include "LessonsPage.h"
#include "AddLessonPage.h"
#include "LessonsViewPage.h"

using namespace std;

Window::Window()
{
	this->console = GetStdHandle(STD_OUTPUT_HANDLE);

	this->pages[0] = new MenuPage(this);
	this->pages[1] = new StudentsPage(this);
	this->pages[2] = new StaffPage(this);
	this->pages[3] = new LessonsPage(this);
	this->pages[4] = new AddStudentPage(this, (StudentsPage*)this->pages[1]);
	this->pages[5] = new StudentsViewPage(this, (StudentsPage*)this->pages[1]);
	this->pages[6] = new AddStaffMemberPage(this, (StaffPage*)this->pages[2]);
	this->pages[7] = new StaffViewPage(this, (StaffPage*)this->pages[2]);
	this->pages[8] = new AddLessonPage(this, (LessonsPage*)this->pages[3]);
	this->pages[9] = new LessonsViewPage(this, (LessonsPage*)this->pages[3]);

	StudentsPage* studentsPage = (StudentsPage*)this->pages[1];
	LessonsPage* lessonsPage = (LessonsPage *)this->pages[3];

	studentsPage->init(lessonsPage->getLessonsList());

	//this->pages[1] = studentsPage;

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

