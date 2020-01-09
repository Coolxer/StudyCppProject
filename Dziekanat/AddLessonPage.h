#pragma once
#include "AddPage.h"

class AddLessonPage: public AddPage
{
private:
	TextBox header;
public:
	AddLessonPage(Window* window);
	~AddLessonPage();

	void draw();
	void service();
};

