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


