#pragma once
#include <iostream>
#include <vector>

#include "Student.h"
#include "StaffMember.h"

class Lesson
{
private:
	int index;

	std::string type;
	std::string name;
	int startTime;
	int duration;

	int maxPlaces;
	int occupiedPlaces;

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
	int getOccupiedPlaces() const;

	StaffMember* getStaffMember() const;

	void setIndex(int index);

	int consistsStudent(Student* student);

	void removeStudent(Student* student, int id);
	void removeStaffMember();

	bool addStudent(Student* student);
	bool setStaffMember(StaffMember* staffMember);
	
	bool showStudents();

	static void showHeader();
	void show(bool withHeader = false);
};

