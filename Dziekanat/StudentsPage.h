#pragma once
#include "Page.h"

#include "TextBox.h"
#include "StudentsList.h"

class StudentsPage : public Page
{
private:
	TextBox header;
	StudentsList studentsList;
public:
	StudentsPage(Window *window);

	void draw();
	void service();
};

