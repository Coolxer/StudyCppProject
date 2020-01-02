#include "Window.h"

#include <iostream>

using namespace std;

Window::Window()
{
	this->tileBox = TextBox("##     DZIEKANAT     ##");
	this->infoBox = TextBox("## Podaj nr operacji ##");

	this->console = GetStdHandle(STD_OUTPUT_HANDLE);
	this->refresh();
}

void Window::clear()
{
	system("cls");
}

void Window::refresh()
{
	this->clear();

	SetConsoleTextAttribute(this->console, FOREGROUND_GREEN);
	this->tileBox.show();
	SetConsoleTextAttribute(this->console, FOREGROUND_RED);
	this->menu.show();
	SetConsoleTextAttribute(this->console, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	this->infoBox.show();
}

