#pragma once
#include "AddPage.h"

class AddLessonPage: public AddPage
{
private:
	TextBox header;
	TextBox info;
public:
	AddLessonPage(Window* window, ObjectList* objectList);
	~AddLessonPage();

	void draw();
	void service();
};

