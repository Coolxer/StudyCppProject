#pragma once
#include <string>
#include "Page.h"
#include "TextBox.h"

#include "StaffPage.h"

class StaffViewPage : public Page
{
private:
	TextBox header;
	TextBox info;

	StaffList* staffList;

public:
	StaffViewPage(Window* window, StaffPage* staffPage);

	void draw();
	void service();
};

