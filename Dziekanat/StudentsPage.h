#pragma once
#include "Page.h"
#include "TextBox.h"
#include "MenuStudent.h"
#include "StudentsList.h"

class StudentsPage : public Page
{
private:
	TextBox header;
	MenuStudent menuStudent;
	TextBox info;

	StudentsList studentsList;
public:
	StudentsPage(Window *window);

	StudentsList* getStudentsList();

	void draw();
	void service();
};

