#pragma once
#include "Page.h"

Page::Page(Window* window) 
{  
	this->window = window;  
}

Page::Page(const Page& model)
{
	this->window = model.window;
}

Page& Page::operator = (const Page& model)
{
	this->window = model.window;

	return *this;
}

Page::~Page()
{
	
}

Window* Page::getWindow() 
{ 
	return this->window; 
}

void Page::onSuccess(string str, int value)
{
	SetConsoleTextAttribute(this->window->getConsole(), 10);
	if (value != -1)
		cout << endl << str << " " << value << endl;
	else
		cout << endl << str << endl;
	SetConsoleTextAttribute(this->window->getConsole(), 15);
}

void Page::onFailure(string str)
{
	SetConsoleTextAttribute(this->window->getConsole(), 12);
	cout << endl << str << endl;
	SetConsoleTextAttribute(this->window->getConsole(), 15);
}


