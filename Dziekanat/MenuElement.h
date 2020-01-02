#pragma once
#include <string>

class MenuElement
{
private:
	int number;
	std::string name;

public:
	MenuElement() {}
	MenuElement(int number, std::string name);

	void show();};

