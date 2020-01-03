#include "Window.h"

#include <iostream>

using namespace std;

Window::Window()
{
	this->console = GetStdHandle(STD_OUTPUT_HANDLE);

	this->pages[0] = new MenuPage(this->console);

	this->drawPage(0);
}

Window::~Window()
{
	for (int i = 0; i < 1; i++)
		delete this->pages[i];
}

void Window::clear()
{
	system("cls");
}

void Window::drawPage(int pageIndex)
{
	this->clear();
	this->pages[pageIndex]->draw();
}

