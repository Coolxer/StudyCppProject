#pragma once
#include <iostream>

class Lesson
{
private:
	int id;
	std::string type;
	std::string name;
	int startTime;
	int duration;

public:
	Lesson() {}
	Lesson(std::string type, std::string name, int startTime, int duration);

	void setId(int id);

	int getId() const;
	std::string getType() const;
	std::string getName() const;
	int getStartTime() const;
	int getDuration() const;

	void show(bool withHeader = false);
};

