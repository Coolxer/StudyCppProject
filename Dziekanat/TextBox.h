#pragma once
#include <string>

class TextBox
{
private:
	char type;
	std::string text;
public:
	TextBox() {}
	TextBox(char type, std::string text);
	void show();
};

