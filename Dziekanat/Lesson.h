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

	int maxPlaces;
	int freePlaces;

public:
	Lesson() {}
	Lesson(std::string type, std::string name, int startTime, int duration, int maxPlaces);

	void setId(int id);

	int getId() const;
	std::string getType() const;
	std::string getName() const;
	int getStartTime() const;
	int getDuration() const;

	int getMaxPlaces() const;
	int getFreePlaces() const;

	static void showHeader();
	void show(bool withHeader = false);
};

