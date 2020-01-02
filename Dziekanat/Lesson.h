#pragma once
#include <iostream>

class Lesson
{
private:
	std::string name;
	int startTime;
	int duration;

public:
	Lesson() {}
	Lesson(std::string name, int startTime, int duration);

	int getStartTime();
	int getDuration();
};

