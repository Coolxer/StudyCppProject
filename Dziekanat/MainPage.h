#pragma once
#include "Page.h"
#include "TextBox.h"
#include "ObjectList.h"

class MainPage : public Page
{
private:
	TextBox header;
	ObjectList objectList;
	TextBox info;
public:
	MainPage(Window* window, std::string headerText);

	ObjectList* getObjectList();

	void draw();
	void service();
};

