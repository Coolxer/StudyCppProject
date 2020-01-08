#pragma once
#include "AddPage.h"

class AddStudentPage : public AddPage
{
private:
	TextBox header;
	TextBox info;
public:
	AddStudentPage(Window* window, ObjectList* objectList);
	~AddStudentPage();

	void draw();
	void service();
};

