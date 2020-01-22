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

	/* Utworzenie poszczegolnych stron */
	this->pages[0] = new MenuPage(this);
	this->pages[1] = new StudentPage(this);
	this->pages[2] = new StaffPage(this);
	this->pages[3] = new LessonPage(this);

	this->pages[4] = new AddStudentPage(this);
	this->pages[6] = new AddStaffMemberPage(this);
	this->pages[8] = new AddLessonPage(this);

	this->pages[5] = new ViewPage(this, "          LISTA STUDENTOW ", 1);
	this->pages[7] = new ViewPage(this, "         LISTA PRACOWNIKOW ", 2);
	this->pages[9] = new ViewPage(this, "             LISTA ZAJEC ", 3);

	AddPage* addPage;
	ViewPage* viewPage;

	StudentPage* studentPage = (StudentPage*)this->pages[1];
	addPage = (AddPage*)this->pages[4];
	addPage->init(studentPage->getStudentList()); // przekazanie wskaznika na obiekt typu StudentList
	viewPage = (ViewPage*)this->pages[5];
	viewPage->init(studentPage->getStudentList()); // przekazanie wskaznika na obiekt typu StudentList

	StaffPage* staffPage = (StaffPage*)this->pages[2];
	addPage = (AddPage*)this->pages[6];
	addPage->init(staffPage->getStaffList()); // przekazanie wskaznika na obiekt typu StaffList
	viewPage = (ViewPage*)this->pages[7];
	viewPage->init(staffPage->getStaffList()); // przekazanie wskaznika na obiekt typu StaffList

	LessonPage* lessonPage = (LessonPage*)this->pages[3];
	addPage = (AddPage*)this->pages[8];
	addPage->init(lessonPage->getLessonList()); // przekazanie wskaznika na obiekt typu LessonList
	viewPage = (ViewPage*)this->pages[9];
	viewPage->init(lessonPage->getLessonList()); // przekazanie wskaznika na obiekt typu LessonList

	studentPage->init(lessonPage->getLessonList()); // przekazanie wskaznika na obiekt typu LessonList
	staffPage->init(lessonPage->getLessonList()); // przekazanie wskaznika na obiekt typu LessonList

	this->activePageIndex = 0;
}

Window::Window(const Window& model)
{
	this->console = model.console;
	
	for (int i = 0; i < 10; i++)
		this->pages[i] = model.pages[i];

	this->activePageIndex = model.activePageIndex;
}

Window& Window::operator=(const Window& model)
{
	for (int i = 0; i < 10; i++)
		delete this->pages[i];
	
	this->console = model.console;

	for (int i = 0; i < 10; i++)
		this->pages[i] = model.pages[i];

	this->activePageIndex = model.activePageIndex;

	return *this;
}

Window::~Window()
{
	// zwolnienie pamieci zarezerwowanej dla poszczegolnych stron 
	for (int i = 0; i < 10; i++)
		delete this->pages[i];
}

void Window::clear()
{
	system("cls"); // wyczyszczenie konsoli
}

void Window::drawActivePage()
{
	this->clear();
	this->pages[this->activePageIndex]->draw(); // narysowanie aktualnej strony
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

