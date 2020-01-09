#pragma once
#include "Page.h"
#include "TextBox.h"
#include "ObjectList.h"

#include "Menu.h"

class MainPage : public Page
{
private:
	TextBox header;
	Menu menu;
	TextBox info;

	ObjectList objectList;
public:
	MainPage(Window* window, std::string headerText);

	ObjectList* getObjectList();

	void setMenu(Menu* menu);

	void draw();
	virtual void service() = 0;
};

