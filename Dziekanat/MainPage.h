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

protected:
	ObjectList objectList;
public:
	MainPage(Window* window, std::string headerText);

	void setMenu(Menu* menu);

	ObjectList* getObjectList();

	void draw();
	virtual void service() = 0;
};

