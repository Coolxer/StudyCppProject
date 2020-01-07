#pragma once
#include <string>
#include "Page.h"
#include "TextBox.h"

#include "StudentsPage.h"

class StudentsViewPage : public Page
{
private:
	TextBox header;
	TextBox info;

	StudentsList* studentsList;

public:
	StudentsViewPage(Window* window, StudentsPage* studentsPage);

	void draw();
	void service();
};

