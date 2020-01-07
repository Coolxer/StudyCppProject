#pragma once
#include "Page.h"

#include "MenuElement.h"
#include "TextBox.h"
#include "StaffList.h"

class StaffPage : public Page
{
private:
	TextBox header;
	MenuElement menuElements[6];
	TextBox info;

	StaffList staffList;
public:
	StaffPage(Window* window);

	StaffList* getStaffList();

	void draw();
	void service();
};

