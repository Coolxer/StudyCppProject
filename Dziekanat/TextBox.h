#pragma once
#include <string>

class TextBox
{
private:
	std::string text;
public:
	TextBox() {}
	TextBox(std::string text);
	void show();
};

