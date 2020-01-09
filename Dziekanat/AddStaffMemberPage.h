#pragma once
#include "AddPage.h"

class AddStaffMemberPage : public AddPage
{
private:
	TextBox header;
public:
	AddStaffMemberPage(Window* window);
	~AddStaffMemberPage();

	void draw();
	void service();
};

