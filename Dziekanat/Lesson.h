#pragma once
#include <iostream>

class Lesson
{
private:
	int index;

	std::string type;
	std::string name;
	int startTime;
	int duration;

	int maxPlaces;
	int freePlaces;

public:
	Lesson() {}
	Lesson(std::string type, std::string name, int startTime, int duration, int maxPlaces);

	int getIndex() const;

	std::string getType() const;
	std::string getName() const;
	int getStartTime() const;
	int getDuration() const;

	int getMaxPlaces() const;
	int getFreePlaces() const;

	void setIndex(int index);

	static void showHeader();
	void show(bool withHeader = false);
};

