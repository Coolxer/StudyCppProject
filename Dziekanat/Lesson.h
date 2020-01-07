#pragma once
#include <iostream>
#include <vector>

#include "Student.h"

class StaffMember;

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

	StaffMember* staffMember;
	std::vector <Student> students;

public:
	Lesson() {}
	~Lesson();
	Lesson(std::string type, std::string name, int startTime, int duration, int maxPlaces);

	int getIndex() const;

	std::string getType() const;
	std::string getName() const;
	int getStartTime() const;
	int getDuration() const;

	int getMaxPlaces() const;
	int getFreePlaces() const;

	StaffMember* getStaffMember() const;

	void setIndex(int index);
	bool setStaffMember(StaffMember* staffMember);
	bool addStudent(Student* student);

	static void showHeader();
	void show(bool withHeader = false);
};

