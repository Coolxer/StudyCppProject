#pragma once
#include "MainPage.h"

#include "StudentList.h"
#include "LessonList.h"

class StudentPage : public MainPage
{
private:
	Menu menu;

	StudentList studentList;
	LessonList* lessonList;
public:
	StudentPage(Window* window);
	~StudentPage();

	StudentList* getStudentList();

	void init(LessonList* lessonList);

	void service();
};

