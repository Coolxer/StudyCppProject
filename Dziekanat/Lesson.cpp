#include "Lesson.h"

#include <iostream>
#include "windows.h"

Lesson::Lesson(std::string type, std::string name, int startTime, int duration, int maxPlaces)
{
	this->type = type;
	this->name = name;
	this->startTime = startTime;
	this->duration = duration;

	this->maxPlaces = maxPlaces;
	this->occupiedPlaces = 0;

	this->staffMember = nullptr;
	this->students.clear();
}

Lesson::~Lesson()
{
	delete this->staffMember;
	this->students.clear();
}

std::string Lesson::getType() const
{
	return this->type;
}

std::string Lesson::getName() const
{
	return this->name;
}

int Lesson::getStartTime() const
{
	return this->startTime;
}

int Lesson::getDuration() const
{
	return this->duration;
}

int Lesson::getMaxPlaces() const
{
	return this->maxPlaces;
}

int Lesson::getOccupiedPlaces() const
{
	return this->occupiedPlaces;
}

StaffMember* Lesson::getStaffMember() const
{
	return this->staffMember;
}

int Lesson::consistsStudent(Student* student)
{
	for (int i = 0; i < (int)this->students.size(); i++)
	{
		if (this->students[i] == *student)
			return i;
	}

	return -1;
}

void Lesson::removeStudent(Student* student, int id)
{
	this->students.erase(this->students.begin() + id);
	this->occupiedPlaces--;
}

void Lesson::removeStaffMember()
{
	//delete this->staffMember;
	this->staffMember = nullptr;
}

bool Lesson::addStudent(Student* student)
{
	if (this->occupiedPlaces < this->maxPlaces)
	{
		for (int i = 0; i < (int)this->students.size(); i++)
		{
			if (this->students[i] == *student)
				return false;
		}

		this->students.push_back(*student);
		this->occupiedPlaces++;
		return true;
	}
	return false;
}

bool Lesson::setStaffMember(StaffMember* staffMember)
{
	if (this->staffMember)
		return false;

	this->staffMember = staffMember;

	return true;
}

bool Lesson::showStudents()
{
	if (this->students.size() == 0)
		return false;

	Student::showHeader();

	for (int i = 0; i < (int)this->students.size(); i++)
		this->students[i].show();

	return true;
}

void Lesson::showHeader()
{
	std::cout << " ID " << " Typ " << " Nazwa " << " Godzina rozpoczecia " << " Czas trwania " << " zajete / max "<< std::endl;
}

void Lesson::show(bool withHeader)
{
	if (withHeader)
		this->showHeader();

	std::cout << "-----------------" << std::endl;
	std::cout << this->getIndex() << " | " << this->type << " | " << this->name << " | " << this->startTime << " | " << this->duration << " | " << this->occupiedPlaces << "/" << this->maxPlaces << std::endl;
}
