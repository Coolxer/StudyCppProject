#pragma once
#include "Page.h"
#include "TextBox.h"
#include "ObjectList.h"

class ViewPage: public Page
{
private:
	TextBox header;
	TextBox info;

	ObjectList* objectList;

	int parentWindowIndex;

public:
	ViewPage(Window* window, std::string headerText, int parentWindowIndex);

	void init(ObjectList* objectList);

	void draw();
	void service();
};

