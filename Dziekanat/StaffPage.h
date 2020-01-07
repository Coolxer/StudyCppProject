#pragma once
#include "Page.h"
#include "TextBox.h"
#include "MenuStaff.h"
#include "StaffList.h"

class StaffPage : public Page
{
private:
	TextBox header;
	MenuStaff menuStaff;
	TextBox info;

	StaffList staffList;
public:
	StaffPage(Window* window);

	StaffList* getStaffList();

	void draw();
	void service();
};

