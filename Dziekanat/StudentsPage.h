#pragma once
#include "Page.h"
#include "TextBox.h"
#include "MenuStudent.h"

#include "StudentsList.h"
#include "LessonsList.h"

class StudentsPage : public Page
{
private:
	TextBox header;
	MenuStudent menuStudent;
	TextBox info;

	StudentsList studentsList;
	LessonsList* lessonsList;
public:
	StudentsPage(Window *window);
	~StudentsPage();

	void init(LessonsList* lessonsList);

	StudentsList* getStudentsList();

	void draw();
	void service();
};

