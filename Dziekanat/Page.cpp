#pragma once
#include "Page.h"

Page::Page(Window* window) 
{  
	this->window = window; 
}

Window* Page::getWindow() 
{ 
	return this->window; 
}


