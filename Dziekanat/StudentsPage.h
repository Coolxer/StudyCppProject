#pragma once
#include "Page.h"

#include "MenuElement.h"
#include "TextBox.h"
#include "StudentsList.h"

class StudentsPage : public Page
{
private:
	TextBox header;
	MenuElement menuElements[8];
	TextBox info;

	StudentsList studentsList;
public:
	StudentsPage(Window *window);

	StudentsList* getStudentsList();

	void draw();
	void service();
};

