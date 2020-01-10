#pragma once
#include "MainPage.h"

#include "StaffList.h"
#include "LessonList.h"

class StaffPage : public MainPage
{
private:
	Menu menu;

	StaffList staffList;
	LessonList* lessonList;
public:
	StaffPage(Window* window);
	~StaffPage();

	StaffList* getStaffList();

	void init(LessonList* lessonList);

	void service();
};

