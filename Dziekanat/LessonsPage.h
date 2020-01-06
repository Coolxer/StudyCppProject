#pragma once
#include "Page.h"
#include "TextBox.h"

class LessonsPage : public Page
{
private:
	TextBox header;
public:
	LessonsPage(Window* window);

	void draw();
	void service();
};

