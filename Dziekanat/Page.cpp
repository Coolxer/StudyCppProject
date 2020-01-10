#pragma once
#include "Page.h"

Page::Page(Window* window) 
{  
	this->window = window; 
}

Page::~Page()
{
	delete this->window;
}

Window* Page::getWindow() 
{ 
	return this->window; 
}


