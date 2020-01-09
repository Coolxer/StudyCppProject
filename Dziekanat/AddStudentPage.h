#pragma once
#include "AddPage.h"

class AddStudentPage : public AddPage
{
private:
	TextBox header;
public:
	AddStudentPage(Window* window);
	~AddStudentPage();

	void draw();
	void service();
};

