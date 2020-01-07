#include "StaffList.h"

#include <iostream>

StaffList::StaffList()
{
	this->startId = 0;

	this->addMember(new StaffMember("Mariusz", "Nycz", 50, "mgr inz"));
	this->addMember(new StaffMember("Mariusz", "Maczka", 60, "prof"));
}

StaffList::~StaffList()
{
	this->staffMembers.clear();
}

int StaffList::addMember(StaffMember* s)
{
	this->staffMembers.push_back(*s);

	this->startId++;
	this->staffMembers.back().setId(this->startId);

	return this->startId;
}

int StaffList::removeMember(int id)
{
	for (int i = 0; i < (int)this->staffMembers.size(); i++)
	{
		if (this->staffMembers[i].getId() == id)
		{
			this->staffMembers.erase(this->staffMembers.begin() + i);
			return id;
		}
	}
	return 0;
}

bool StaffList::showStaff()
{
	for (int i = 0; i < (int)this->staffMembers.size(); i++)
		this->staffMembers[i].show();

	if (this->staffMembers.size() != 0)
		return true;

	return false;
}

bool StaffList::showMemberbyId(int id)
{
	for (int i = 0; i < (int)this->staffMembers.size(); i++)
	{
		if (this->staffMembers[i].getId() == id)
		{
			this->staffMembers[i].show(true);
			return true;
		}
	}
	return false;
}

bool StaffList::showProfessors()
{
	int count = 0;
	for (int i = 0; i < (int)this->staffMembers.size(); i++)
	{
		if (this->staffMembers[i].isProfessor())
		{
			this->staffMembers[i].show();
			count++;
		}
	}

	if (count > 0)
		return true;

	return false;
}

int StaffList::getNumberOfMembers()
{
	return (int)this->staffMembers.size();
}

