#pragma once
#include "Page.h"
#include "TextBox.h"
#include "MenuStaff.h"

#include "StaffList.h"
#include "LessonsPage.h"

class StaffPage : public Page
{
private:
	TextBox header;
	MenuStaff menuStaff;
	TextBox info;

	StaffList staffList;
	LessonsList* lessonsList;
public:
	StaffPage(Window* window);

	void init(LessonsList* lessonsList);

	StaffList* getStaffList();

	void draw();
	void service();
};

