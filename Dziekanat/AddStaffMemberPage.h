#pragma once
#include "AddPage.h"

class AddStaffMemberPage : public AddPage
{
private:
	TextBox header;
	TextBox info;
public:
	AddStaffMemberPage(Window* window, ObjectList* objectList);
	~AddStaffMemberPage();

	void draw();
	void service();
};

