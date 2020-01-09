#pragma once
#include <iostream>
#include <vector>

#include "Student.h"
#include "StaffMember.h"

#include "Object.h"

class Lesson: public Object
{
private:
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

	std::string getType() const;
	std::string getName() const;
	int getStartTime() const;
	int getDuration() const;
	int getMaxPlaces() const;
	int getOccupiedPlaces() const;

	StaffMember* getStaffMember() const;

	int consistsStudent(Student* student);

	void removeStudent(Student* student, int id);
	void removeStaffMember();

	bool addStudent(Student* student);
	bool setStaffMember(StaffMember* staffMember);
	
	bool showStudents();

	void showHeader();
	void show(bool withHeader = false);
};

